using System.Globalization;
using BIS.Core;
using BIS.Core.Math;

static class Move
{
    public static void Run(string input, string output, string lodName, string selection, float[] delta)
    {
        var odol = Odol.Load(input);
        var lod = Odol.FindLod(odol, lodName);
        int[] sections;
        if (selection.StartsWith('#')) sections = [int.Parse(selection[1..])];
        else
        {
            var ns = lod.NamedSelections.FirstOrDefault(n => n.Name.Equals(selection, StringComparison.OrdinalIgnoreCase)) ?? throw new Exception($"no selection {selection}");
            if (!ns.IsSectional || ns.Sections.Count == 0) throw new Exception($"{selection} is not a sectional selection");
            sections = ns.Sections.ToArray();
        }

        var own = sections.SelectMany(s => Selections.FacesInSection(lod, lod.Sections[s])).ToHashSet();
        if (own.Count == 0) throw new Exception("no faces match");
        var verts = own.SelectMany(f => lod.Polygons.Faces[f].VertexIndices).ToHashSet();
        var shared = Enumerable.Range(0, lod.Polygons.Faces.Length).Where(f => !own.Contains(f))
            .SelectMany(f => lod.Polygons.Faces[f].VertexIndices).Count(verts.Contains);
        if (shared > 0) throw new Exception($"{shared} vertices are shared with faces outside {selection}");

        var moved = lod.Vertices.Select((p, i) => verts.Contains(i) ? new Vector3P(p.X + delta[0], p.Y + delta[1], p.Z + delta[2]) : p);
        Odol.Set(typeof(BIS.P3D.ODOL.LOD), lod, "Vertices", new TrackedArray<Vector3P>(moved));
        var p = verts.Select(v => lod.Vertices[v]).ToList();
        Console.WriteLine(string.Create(CultureInfo.InvariantCulture, $"{selection}: {verts.Count} vertices now x {p.Min(q => q.X):F3}..{p.Max(q => q.X):F3} y {p.Min(q => q.Y):F3}..{p.Max(q => q.Y):F3} z {p.Min(q => q.Z):F3}..{p.Max(q => q.Z):F3}"));
        Odol.Save(odol, output);
    }
}
