using System.Numerics;
using System.Text.Json;
using BIS.Core;
using BIS.Core.Math;
using BIS.P3D.ODOL;

// Cuts UV seams by duplicating vertices, so a closed or heavily curved surface can be flattened in pieces.
// Plan: {"copies": [srcVertex, ...], "faces": [{"verts": [v0, v1, ...], "map": {"old": newIndex}}]}.
// copies[i] becomes vertex VertexCount + i, with the source's position, normal, ST, UVs, clip flag,
// point, bone references and selection membership. Each listed face, found by its vertex list,
// then points at the new vertices given in "map".
static class Seams
{
    public static void Cut(string input, string output, string lodName, string planFile)
    {
        var odol = Odol.Load(input);
        var lod = Odol.FindLod(odol, lodName);
        var plan = JsonDocument.Parse(File.ReadAllText(planFile)).RootElement;
        var copies = plan.GetProperty("copies").EnumerateArray().Select(e => e.GetInt32()).ToArray();
        int n0 = lod.Vertices.Count;
        if ((typeof(LOD).GetProperty("Frames", Odol.Any).GetValue(lod) as Array)?.Length > 0) throw new Exception("LOD has keyframes; not supported");

        T[] Grow<T>(IEnumerable<T> a) { var l = a.ToList(); foreach (var c in copies) l.Add(l[c]); return l.ToArray(); }
        Odol.Set(typeof(LOD), lod, "Vertices", new TrackedArray<Vector3P>(Grow(lod.Vertices)));
        Odol.Set(typeof(LOD), lod, "NormalsCompressed", new TrackedArray<Vector3PCompressed>(Grow(lod.NormalsCompressed)));
        Odol.Set(typeof(LOD), lod, "STCoordsCompressed", new TrackedArray<Tuple<Vector3PCompressed, Vector3PCompressed>>(Grow(lod.STCoordsCompressed)));
        if (lod.Clip.Count == n0) Odol.Set(typeof(LOD), lod, "Clip", new TrackedArray<int>(Grow(lod.Clip)));
        if (lod.VertexToPoint.Count == n0) Odol.Set(typeof(LOD), lod, "VertexToPoint", new TrackedArray<int>(Grow(lod.VertexToPoint)));
        var bones = Odol.BoneRefs(lod);
        if (bones.Count == n0) Odol.SetBoneRefs(lod, Grow(bones).ToList());
        var neigh = ((System.Collections.IEnumerable)typeof(LOD).GetProperty("NeighborBoneRef", Odol.Any).GetValue(lod))?.Cast<object>().ToList();
        if (neigh != null && neigh.Count == n0)
        {
            var list = neigh; foreach (var c in copies) list.Add(list[c]);
            var arr = Array.CreateInstance(list[0].GetType(), list.Count);
            for (int i = 0; i < list.Count; i++) arr.SetValue(list[i], i);
            Odol.Set(typeof(LOD), lod, "NeighborBoneRef", Activator.CreateInstance(typeof(TrackedArray<>).MakeGenericType(list[0].GetType()), arr));
        }
        else if (neigh != null && neigh.Count != 0) throw new Exception($"NeighborBoneRef has {neigh.Count} entries for {n0} vertices");
        foreach (var set in lod.UvSets)
        {
            Uv.WriteUv(set, Grow(set.GetUV()));
            Odol.Set(typeof(UVSet), set, "NVertices", (uint)(n0 + copies.Length));
        }
        Odol.Set(typeof(LOD), lod, "VertexCount", (uint)(n0 + copies.Length));

        // a copy joins every selection its source is in, with the same weight
        var srcCopies = new Dictionary<int, List<int>>();
        for (int i = 0; i < copies.Length; i++) (srcCopies.TryGetValue(copies[i], out var l) ? l : srcCopies[copies[i]] = new()).Add(n0 + i);
        foreach (var sel in lod.NamedSelections)
        {
            var verts = sel.SelectedVertices.ToList();
            if (verts.Count == 0) continue;
            var weights = sel.SelectedVerticesWeights.ToList();
            bool weighted = weights.Count == verts.Count;
            int added = 0;
            for (int k = 0, m = verts.Count; k < m; k++)
                if (srcCopies.TryGetValue(verts[k], out var cs))
                    foreach (var c in cs) { verts.Add(c); if (weighted) weights.Add(weights[k]); added++; }
            if (added == 0) continue;
            Odol.Set(sel, "SelectedVertices", new TrackedArray<int>(verts));
            if (weighted)
            {
                Odol.Set(sel, "SelectedVerticesWeights", new TrackedArray<byte>(weights));
                Odol.Set(sel, "ExpectedSize", weights.Count);
            }
        }

        var faces = lod.Polygons.Faces;
        var byVerts = new Dictionary<string, int>();
        for (int f = 0; f < faces.Length; f++) byVerts[string.Join(',', faces[f].VertexIndices)] = f;
        int changed = 0;
        foreach (var e in plan.GetProperty("faces").EnumerateArray())
        {
            var key = string.Join(',', e.GetProperty("verts").EnumerateArray().Select(x => x.GetInt32()));
            if (!byVerts.TryGetValue(key, out var f)) throw new Exception($"no face with vertices {key}");
            var idx = faces[f].VertexIndices;
            foreach (var p in e.GetProperty("map").EnumerateObject())
            {
                int from = int.Parse(p.Name), to = p.Value.GetInt32(), k = Array.IndexOf(idx, from);
                if (k < 0) throw new Exception($"face {key} has no vertex {from}");
                if (to < n0 || copies[to - n0] != from) throw new Exception($"vertex {to} is not a copy of {from}");
                idx[k] = to;
            }
            changed++;
        }
        Console.WriteLine($"{copies.Length} vertices duplicated, {changed} faces re-pointed; LOD now has {lod.Vertices.Count} vertices");
        Odol.Save(odol, output);
    }
}
