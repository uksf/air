using System.Numerics;
using BIS.Core;
using BIS.Core.Math;
using BIS.P3D.ODOL;

// Model edits. Geometry added to the memory LOD copies its layout from a template model whose memory
// LOD already has proxy triangles and single-vertex points (the A-143 Buzzard works).
static class Edits
{
    // Retargets proxies. Each rule is "oldModel|oldId|newModel|newId"; forward slashes are accepted.
    // The proxy's named selection is renamed to match, in every LOD.
    public static void Remap(string input, string output, IEnumerable<string> ruleArgs)
    {
        var odol = Odol.Load(input);
        var rules = ruleArgs.Select(a => a.Split('|'))
            .Select(p => (oldM: Path(p[0]), oldId: int.Parse(p[1]), newM: Path(p[2]), newId: int.Parse(p[3]))).ToList();
        var used = new HashSet<(string, int)>();
        foreach (var lod in odol.Lods)
        {
            int hits = 0;
            foreach (var p in Odol.RawProxies(lod))
            {
                var name = Odol.Get<string>(p, "ProxyModel").ToLowerInvariant();
                var seq = Odol.Get<int>(p, "SequenceID");
                var r = rules.FirstOrDefault(r => r.oldM == name && r.oldId == seq);
                if (r.oldM == null) continue;
                Odol.Set(p, "ProxyModel", r.newM);
                Odol.Set(p, "SequenceID", r.newId);
                var ns = lod.NamedSelections[Odol.Get<int>(p, "NamedSelectionIndex")];
                Odol.Set(typeof(NamedSelection), ns, "Name", $"proxy:{r.newM}.{r.newId:000}");
                used.Add((r.oldM, r.oldId));
                hits++;
            }
            if (hits > 0) Console.WriteLine($"LOD {lod.Resolution:G6}: remapped {hits}");
        }
        foreach (var r in rules.Where(r => !used.Contains((r.oldM, r.oldId)))) Console.WriteLine($"UNUSED rule {r.oldM}|{r.oldId}");
        Odol.Save(odol, output);
    }

    static string Path(string p) => p.Replace('/', '\\').ToLowerInvariant();

    // Points a model animation at a different config AnimationSources entry. The config must define
    // that source, or the engine logs "unknown animation source" and the animation stays still.
    public static void SetSource(string input, string output, string animName, string source)
    {
        var odol = Odol.Load(input);
        var hits = odol.Animations.AnimationClasses.Where(a => a.AnimName.Equals(animName, StringComparison.OrdinalIgnoreCase)).ToList();
        if (hits.Count == 0) throw new Exception($"no animation {animName}");
        foreach (var a in hits)
        {
            Console.WriteLine($"{a.AnimName}: source {a.AnimSource} -> {source}");
            Odol.Set(typeof(AnimationClass), a, "AnimSource", source);
        }
        Odol.Save(odol, output);
    }

    // Appends one vertex copying the template vertex's clip flag, normal and bone reference.
    static int AppendVertex(LOD mem, LOD tmem, int templateVertex, Vector3 p, List<object> boneRefs, object tBoneRef)
    {
        int v = mem.Vertices.Count;
        Odol.Set(typeof(LOD), mem, "Vertices", new TrackedArray<Vector3P>(mem.Vertices.Append(new Vector3P(p.X, p.Y, p.Z))));
        Odol.Set(typeof(LOD), mem, "Clip", new TrackedArray<int>(mem.Clip.Append(tmem.Clip[templateVertex])));
        Odol.Set(typeof(LOD), mem, "NormalsCompressed", new TrackedArray<Vector3PCompressed>(mem.NormalsCompressed.Append(tmem.NormalsCompressed[templateVertex])));
        boneRefs.Add(tBoneRef);
        Odol.Set(typeof(LOD), mem, "VertexCount", (uint)(v + 1));
        Odol.Set(typeof(UVSet), mem.UvSets[0], "NVertices", (uint)(v + 1));
        return v;
    }

    // Copies every LOD 0 proxy whose path contains the filter into the memory LOD as a proxy triangle.
    // Dynamic pylons need these: the engine takes store positions from memory-LOD proxies.
    // Only supports a memory LOD with no faces yet, which is the usual case for models without them.
    public static void AddMemoryProxies(string input, string output, string template, string filter)
    {
        var odol = Odol.Load(input);
        var tmem = Odol.FindLod(Odol.Load(template), "memory");
        var src = Odol.FindLod(odol, "0");
        var mem = Odol.FindLod(odol, "memory");
        if (mem.Polygons.Faces.Length != 0 || mem.Sections.Length != 0) throw new Exception("memory LOD already has faces");
        if (Odol.RawProxies(tmem).Length == 0) throw new Exception("template memory LOD has no proxies");

        var tProxy = Odol.RawProxies(tmem).GetValue(0);
        var proxyType = tProxy.GetType();
        var tSel = tmem.NamedSelections[Odol.Get<int>(tProxy, "NamedSelectionIndex")];
        int tVertex = tSel.SelectedVertices[0];
        var tFace = tmem.Polygons.Faces[tSel.SelectedFaces[0]];
        var tBoneRef = Odol.BoneRefs(tmem)[tVertex];
        var boneRefs = Odol.BoneRefs(mem);

        var srcProxies = Odol.RawProxies(src).Cast<object>()
            .Where(p => Odol.Get<string>(p, "ProxyModel").Contains(filter, StringComparison.OrdinalIgnoreCase))
            .OrderBy(p => Odol.Get<int>(p, "SequenceID")).ToList();
        if (srcProxies.Count == 0) throw new Exception($"no LOD 0 proxies match '{filter}'");

        var faces = new List<Polygon>();
        var selections = mem.NamedSelections.ToList();
        var proxies = new List<object>();
        foreach (var sp in srcProxies)
        {
            var matrix = Odol.Get<Matrix4P>(sp, "Transformation");
            var m = matrix.Matrix;
            var pos = new Vector3(m.M41, m.M42, m.M43);
            var y = new Vector3(m.M21, m.M22, m.M23);
            var z = new Vector3(m.M31, m.M32, m.M33);
            // Proxy triangle: origin, +Y and half +Z, as Bohemia's tools write it.
            int v0 = AppendVertex(mem, tmem, tVertex, pos, boneRefs, tBoneRef);
            AppendVertex(mem, tmem, tVertex, pos + y, boneRefs, tBoneRef);
            AppendVertex(mem, tmem, tVertex, pos + 0.5f * z, boneRefs, tBoneRef);
            var face = (Polygon)Odol.Clone(tFace);
            Odol.Set(face, "VertexIndices", new[] { v0 + 1, v0, v0 + 2 });
            faces.Add(face);

            var seq = Odol.Get<int>(sp, "SequenceID");
            var model = Odol.Get<string>(sp, "ProxyModel");
            var ns = (NamedSelection)Odol.Clone(tSel);
            Odol.Set(ns, "Name", $"proxy:{model}.{seq:000}");
            Odol.Set(ns, "SelectedFaces", new TrackedArray<int>(new[] { faces.Count - 1 }));
            Odol.Set(ns, "SelectedVertices", new TrackedArray<int>(new[] { v0, v0 + 1, v0 + 2 }));
            selections.Add(ns);

            var proxy = Odol.Clone(tProxy);
            Odol.Set(proxyType, proxy, "ProxyModel", model);
            Odol.Set(proxyType, proxy, "Transformation", matrix);
            Odol.Set(proxyType, proxy, "SequenceID", seq);
            Odol.Set(proxyType, proxy, "NamedSelectionIndex", selections.Count - 1);
            Odol.Set(proxyType, proxy, "BoneIndex", -1);
            Odol.Set(proxyType, proxy, "SectionIndex", 0);
            proxies.Add(proxy);
        }

        // Faces take 4 + 4 bytes per index at version >= 69; sections address them by byte offset.
        int faceBytes = faces.Sum(f => 4 + 4 * f.VertexIndices.Length);
        var polys = (Polygons)Odol.Clone(tmem.Polygons);
        Odol.Set(polys, "Faces", faces.ToArray());
        Odol.Set(polys, "Unused1", (uint)faceBytes);
        var section = (Section)Odol.Clone(tmem.Sections[0]);
        Odol.Set(section, "FaceLowerIndex", 0);
        Odol.Set(section, "FaceUpperIndex", faceBytes);

        var proxyArray = Array.CreateInstance(proxyType, proxies.Count);
        for (int i = 0; i < proxies.Count; i++) proxyArray.SetValue(proxies[i], i);
        Odol.Set(typeof(LOD), mem, "RawProxies", proxyArray);
        Odol.SetBoneRefs(mem, boneRefs);
        Odol.Set(typeof(LOD), mem, "Polygons", polys);
        Odol.Set(typeof(LOD), mem, "Sections", new[] { section });
        mem.NamedSelections = selections.ToArray();
        if (mem.Textures.Length == 0) Odol.Set(typeof(LOD), mem, "Textures", new[] { "" });

        Console.WriteLine($"memory LOD: +{proxies.Count} proxies, {mem.Vertices.Count} vertices, {faces.Count} faces");
        Odol.Save(odol, output);
    }

    // Adds a named single-vertex point to the memory LOD. Model coordinates: +X right, +Y up; check
    // which way Z points on the model with `points` before placing anything fore or aft.
    public static void AddPoint(string input, string output, string template, string name, Vector3 p)
    {
        var odol = Odol.Load(input);
        var tmem = Odol.FindLod(Odol.Load(template), "memory");
        var mem = Odol.FindLod(odol, "memory");
        if (mem.NamedSelections.Any(n => n.Name.Equals(name, StringComparison.OrdinalIgnoreCase))) throw new Exception($"selection {name} exists");
        var tSel = tmem.NamedSelections.First(n => n.SelectedVertices.Count == 1 && n.SelectedFaces.Count == 0);
        int tv = tSel.SelectedVertices[0];
        var boneRefs = Odol.BoneRefs(mem);
        int v = AppendVertex(mem, tmem, tv, p, boneRefs, Odol.BoneRefs(tmem)[tv]);
        Odol.SetBoneRefs(mem, boneRefs);
        var ns = (NamedSelection)Odol.Clone(tSel);
        Odol.Set(ns, "Name", name);
        Odol.Set(ns, "SelectedVertices", new TrackedArray<int>(new[] { v }));
        Odol.Set(ns, "SelectedFaces", new TrackedArray<int>());
        mem.NamedSelections = mem.NamedSelections.Append(ns).ToArray();
        Console.WriteLine($"memory LOD: +point {name} as vertex {v}");
        Odol.Save(odol, output);
    }
}
