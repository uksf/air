using System.Globalization;
using BIS.P3D.ODOL;

// Resolves a named selection to vertices. Visual-LOD selections are often sectional: they list
// sections, not vertices, so the vertices come from the faces inside those sections.
static class Selections
{
    // Faces are addressed by byte offset: 4 + 4 bytes per index at version >= 69.
    public static List<int> FacesInSection(LOD lod, Section s)
    {
        var faces = new List<int>();
        int offset = 0;
        for (int f = 0; f < lod.Polygons.Faces.Length; f++)
        {
            if (offset >= s.FaceLowerIndex && offset < s.FaceUpperIndex) faces.Add(f);
            offset += 4 + 4 * lod.Polygons.Faces[f].VertexIndices.Length;
        }
        return faces;
    }

    public static int[] Vertices(LOD lod, NamedSelection ns)
    {
        var faces = ns.SelectedFaces.ToList();
        foreach (var s in ns.Sections) faces.AddRange(FacesInSection(lod, lod.Sections[s]));
        return faces.SelectMany(f => lod.Polygons.Faces[f].VertexIndices).Concat(ns.SelectedVertices).Distinct().OrderBy(v => v).ToArray();
    }

    // Weights every vertex of a sectional selection fully to one bone, so an animation on that bone
    // moves it. Each section may only use a window of bones (MinBoneIndex, BonesCount), so the
    // selection's sections move their window to include the bone. Only unweighted vertices that no
    // other section shares are touched.
    // selection may be "#N" for section N. box keeps only faces with every vertex inside it.
    public static void Bind(string input, string output, string lodName, string selection, string bone, float[] box)
    {
        var odol = Odol.Load(input);
        var lod = Odol.FindLod(odol, lodName);
        var names = odol.ModelInfo.Skeleton.SkeletonBoneNames.Select(b => b.BoneName).ToArray();
        int sub = Array.FindIndex(lod.SubSkeletonsToSkeleton, b => names[b].Equals(bone, StringComparison.OrdinalIgnoreCase));
        if (sub < 0) throw new Exception($"no bone {bone} in LOD {lodName}");
        int[] sections;
        if (selection.StartsWith('#')) sections = [int.Parse(selection[1..])];
        else
        {
            var ns = lod.NamedSelections.FirstOrDefault(n => n.Name.Equals(selection, StringComparison.OrdinalIgnoreCase)) ?? throw new Exception($"no selection {selection}");
            if (!ns.IsSectional || ns.Sections.Count == 0) throw new Exception($"{selection} is not a sectional selection");
            sections = ns.Sections.ToArray();
        }

        bool Inside(int v) => box == null || (lod.Vertices[v].X >= box[0] && lod.Vertices[v].X <= box[1] && lod.Vertices[v].Y >= box[2] && lod.Vertices[v].Y <= box[3] && lod.Vertices[v].Z >= box[4] && lod.Vertices[v].Z <= box[5]);
        var own = sections.SelectMany(s => FacesInSection(lod, lod.Sections[s])).Where(f => lod.Polygons.Faces[f].VertexIndices.All(Inside)).ToHashSet();
        if (own.Count == 0) throw new Exception("no faces match");
        var verts = own.SelectMany(f => lod.Polygons.Faces[f].VertexIndices).Distinct().ToArray();
        var ext = verts.Select(v => lod.Vertices[v]).ToList();
        Console.WriteLine(string.Create(CultureInfo.InvariantCulture, $"{own.Count} faces, {verts.Length} vertices: x {ext.Min(q => q.X):F3}..{ext.Max(q => q.X):F3} y {ext.Min(q => q.Y):F3}..{ext.Max(q => q.Y):F3} z {ext.Min(q => q.Z):F3}..{ext.Max(q => q.Z):F3}"));
        var shared = Enumerable.Range(0, lod.Polygons.Faces.Length).Where(f => !own.Contains(f))
            .SelectMany(f => lod.Polygons.Faces[f].VertexIndices).Intersect(verts).Count();
        if (shared > 0) throw new Exception($"{shared} vertices are shared with faces outside {selection}");

        var refs = Odol.BoneRefs(lod);
        if (verts.Any(v => Odol.Get<int>(refs[v], "Count") != 0)) throw new Exception($"{selection} already has bone weights");
        var template = refs.First(r => Odol.Get<int>(r, "Count") == 1);
        foreach (var v in verts)
        {
            var r = Odol.Clone(template);
            var data = (byte[])Odol.Get<byte[]>(template, "Data").Clone();
            data[0] = (byte)sub;
            Odol.Set(r, "Data", data);
            refs[v] = r;
        }
        Odol.SetBoneRefs(lod, refs);

        foreach (var s in sections)
        {
            var sec = lod.Sections[s];
            if (sub >= sec.MinBoneIndex && sub < sec.MinBoneIndex + sec.BonesCount) continue;
            int min = Math.Max(0, sub - sec.BonesCount + 1);
            Console.WriteLine($"section {s}: bone window {sec.MinBoneIndex}..{sec.MinBoneIndex + sec.BonesCount - 1} -> {min}..{min + sec.BonesCount - 1}");
            Odol.Set(typeof(Section), sec, "MinBoneIndex", min);
        }
        Console.WriteLine($"{selection}: {verts.Length} vertices bound to {bone} (sub-skeleton {sub})");
        Odol.Save(odol, output);
    }

    // Every section in a LOD with its texture, vertex extent and bones, optionally only sections with
    // a vertex inside a box. Finds the geometry behind a visible part that has no useful selection.
    public static void ListSections(string input, string lodName, float[] box)
    {
        var odol = Odol.Load(input);
        var lod = Odol.FindLod(odol, lodName);
        var names = odol.ModelInfo.Skeleton.SkeletonBoneNames.Select(b => b.BoneName).ToArray();
        var refs = Odol.BoneRefs(lod);
        for (int s = 0; s < lod.Sections.Length; s++)
        {
            var sec = lod.Sections[s];
            var verts = FacesInSection(lod, sec).SelectMany(f => lod.Polygons.Faces[f].VertexIndices).Distinct().ToList();
            if (verts.Count == 0) continue;
            var p = verts.Select(v => lod.Vertices[v]).ToList();
            if (box != null && !p.Any(q => q.X >= box[0] && q.X <= box[1] && q.Y >= box[2] && q.Y <= box[3] && q.Z >= box[4] && q.Z <= box[5])) continue;
            string R(Func<BIS.Core.Math.Vector3P, float> f) => string.Create(CultureInfo.InvariantCulture, $"{p.Min(f):F2}..{p.Max(f):F2}");
            var bones = verts.Select(v => Odol.Get<int>(refs[v], "Count") == 0 ? "none" : names[lod.SubSkeletonsToSkeleton[Odol.Get<byte[]>(refs[v], "Data")[0]]])
                .GroupBy(b => b).Select(g => $"{g.Key} x{g.Count()}");
            var tex = sec.TextureIndex >= 0 && sec.TextureIndex < lod.Textures.Length ? lod.Textures[sec.TextureIndex] : "";
            var sels = lod.NamedSelections.Where(n => n.Sections.Contains(s)).Select(n => n.Name);
            Console.WriteLine($"{s,3} '{tex}' {verts.Count} verts x {R(q => q.X)} y {R(q => q.Y)} z {R(q => q.Z)} bones [{string.Join(", ", bones)}] selections [{string.Join(", ", sels)}]");
        }
    }

    public static void Show(string input, string lodName, string name)
    {
        var odol = Odol.Load(input);
        var lod = Odol.FindLod(odol, lodName);
        var names = odol.ModelInfo.Skeleton.SkeletonBoneNames.Select(b => b.BoneName).ToArray();
        var refs = Odol.BoneRefs(lod);
        foreach (var ns in lod.NamedSelections.Where(n => n.Name.Contains(name, StringComparison.OrdinalIgnoreCase)))
        {
            var verts = Vertices(lod, ns);
            Console.WriteLine($"{ns.Name}: sectional {ns.IsSectional}, sections [{string.Join(',', ns.Sections)}], {verts.Length} vertices");
            foreach (var s in ns.Sections) Console.WriteLine($"  section {s}: texture '{(lod.Sections[s].TextureIndex >= 0 && lod.Sections[s].TextureIndex < lod.Textures.Length ? lod.Textures[lod.Sections[s].TextureIndex] : "")}'");
            if (verts.Length == 0) continue;
            var p = verts.Select(v => lod.Vertices[v]).ToList();
            string R(Func<BIS.Core.Math.Vector3P, float> f) => string.Create(CultureInfo.InvariantCulture, $"{p.Min(f):F3}..{p.Max(f):F3}");
            Console.WriteLine($"  x {R(q => q.X)} y {R(q => q.Y)} z {R(q => q.Z)}");
            var bones = verts.Select(v =>
            {
                int count = Odol.Get<int>(refs[v], "Count");
                var data = Odol.Get<byte[]>(refs[v], "Data");
                return count == 0 ? "none" : string.Join('+', Enumerable.Range(0, Math.Min(count, 4)).Select(i => names[lod.SubSkeletonsToSkeleton[data[i * 2]]] + ":" + data[i * 2 + 1]));
            }).GroupBy(b => b).Select(g => $"{g.Key} x{g.Count()}");
            Console.WriteLine($"  bone weights: {string.Join(", ", bones)}");
        }
    }
}
