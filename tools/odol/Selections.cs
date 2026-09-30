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
    public static void Bind(string input, string output, string lodName, string selection, string bone)
    {
        var odol = Odol.Load(input);
        var lod = Odol.FindLod(odol, lodName);
        var names = odol.ModelInfo.Skeleton.SkeletonBoneNames.Select(b => b.BoneName).ToArray();
        int sub = Array.FindIndex(lod.SubSkeletonsToSkeleton, b => names[b].Equals(bone, StringComparison.OrdinalIgnoreCase));
        if (sub < 0) throw new Exception($"no bone {bone} in LOD {lodName}");
        var ns = lod.NamedSelections.FirstOrDefault(n => n.Name.Equals(selection, StringComparison.OrdinalIgnoreCase)) ?? throw new Exception($"no selection {selection}");
        if (!ns.IsSectional || ns.Sections.Count == 0) throw new Exception($"{selection} is not a sectional selection");

        var verts = Vertices(lod, ns);
        var own = ns.Sections.SelectMany(s => FacesInSection(lod, lod.Sections[s])).ToHashSet();
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

        foreach (var s in ns.Sections)
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
