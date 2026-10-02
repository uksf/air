using System.Numerics;
using System.Text.Json;
using BIS.Core;
using BIS.P3D.ODOL;

// Texture-layout edits: move UV islands onto a second texture sheet, and give sections their own
// hidden selection so the config can texture them separately.
static class Uv
{
    record Island(string Sheet, float S, float[] Box, float[] Pos, int[] Verts, float[][] Uv, float[][] St);

    static float[] Floats(JsonElement e) => e.EnumerateArray().Select(x => x.GetSingle()).ToArray();
    static float[][] Rows(JsonElement e, string name) =>
        e.TryGetProperty(name, out var p) ? p.EnumerateArray().Select(Floats).ToArray() : null;

    // Applies a layout plan to one LOD. A plan island either gives each vertex's new UV ("uv", with
    // optional "st" tangents S and T) or moves the island to new UV = (old - box) * s + pos.
    // Faces of islands on sheet "B" are moved behind the sheet-A faces of their section, which is then
    // split; the new sections use newTexture and belong to newSelection instead of selection.
    public static void Split(string input, string output, string lodName, string planFile, string selection, string newSelection, string newTexture)
    {
        var odol = Odol.Load(input);
        var lod = Odol.FindLod(odol, lodName);
        var plan = JsonDocument.Parse(File.ReadAllText(planFile)).RootElement.GetProperty("islands").EnumerateArray()
            .Select(e => new Island(e.GetProperty("sheet").GetString(),
                e.TryGetProperty("s", out var s) ? s.GetSingle() : 1,
                e.TryGetProperty("box", out var b) ? Floats(b) : null,
                e.TryGetProperty("pos", out var p) ? Floats(p) : null,
                e.GetProperty("verts").EnumerateArray().Select(x => x.GetInt32()).ToArray(),
                Rows(e, "uv"), Rows(e, "st"))).ToList();
        var owner = new Dictionary<int, Island>();
        foreach (var i in plan) foreach (var v in i.Verts) owner[v] = i;

        var old = lod.UvSets[0].GetUV();
        var uv = (Vector2[])old.Clone();
        var st = lod.STCoordsCompressed.ToArray();
        foreach (var i in plan)
            for (int k = 0; k < i.Verts.Length; k++)
            {
                int v = i.Verts[k];
                uv[v] = i.Uv != null ? new Vector2(i.Uv[k][0], i.Uv[k][1])
                    : new Vector2((old[v].X - i.Box[0]) * i.S + i.Pos[0], (old[v].Y - i.Box[1]) * i.S + i.Pos[1]);
                if (i.St != null) st[v] = Tuple.Create(Pack(i.St[k], 0), Pack(i.St[k], 3));
            }
        WriteUv(lod.UvSets[0], uv);
        Odol.Set(typeof(LOD), lod, "STCoordsCompressed", new TrackedArray<Tuple<BIS.Core.Math.Vector3PCompressed, BIS.Core.Math.Vector3PCompressed>>(st));

        var faces = lod.Polygons.Faces;
        bool OnB(int f)
        {
            var sheets = faces[f].VertexIndices.Select(v => owner.TryGetValue(v, out var i) ? i.Sheet : null).Distinct().ToList();
            if (sheets.Count != 1) throw new Exception($"face {f} spans islands on sheets {string.Join(',', sheets)}");
            return sheets[0] == "B";
        }
        // AreaOverTex is world area per UV area and drives mip selection; scale it by the change in total
        // UV area, which stays stable where the old map gave faces almost no area.
        float Ratio(List<int> fs) => fs.Sum(f => UvArea(uv, faces[f].VertexIndices)) / Math.Max(fs.Sum(f => UvArea(old, faces[f].VertexIndices)), 1e-12f);

        var textures = lod.Textures.Append(newTexture).ToArray();
        Odol.Set(typeof(LOD), lod, "Textures", textures);
        short texB = (short)(textures.Length - 1);
        var perm = Enumerable.Range(0, faces.Length).ToArray();           // new position -> old face
        var sections = lod.Sections.ToList();
        var selections = lod.NamedSelections.ToList();
        var bSections = new List<int>();
        var target = selections.Single(n => n.Name.Equals(selection, StringComparison.OrdinalIgnoreCase));

        for (int s = sections.Count - 1; s >= 0; s--)
        {
            var sec = sections[s];
            var inSec = Selections.FacesInSection(lod, sec);
            if (!inSec.SelectMany(f => faces[f].VertexIndices).Any(owner.ContainsKey)) continue;
            var a = inSec.Where(f => !OnB(f)).ToList();
            var b = inSec.Where(OnB).ToList();
            float aot = sec.AreaOverTex[0];
            if (a.Count > 0) SetAreaOverTex(sec, aot / Ratio(a));
            if (b.Count == 0) continue;
            var order = a.Concat(b).ToList();
            for (int k = 0; k < order.Count; k++) perm[inSec[0] + k] = order[k];
            int split = sec.FaceLowerIndex + a.Sum(f => 4 + 4 * faces[f].VertexIndices.Length);
            var secB = (Section)Odol.Clone(sec);
            Odol.Set(secB, "FaceLowerIndex", split);
            Odol.Set(secB, "TextureIndex", texB);
            Odol.Set(secB, "AreaOverTex", (float[])sec.AreaOverTex.Clone());
            SetAreaOverTex(secB, aot / Ratio(b));
            if (a.Count == 0)
            {
                sections[s] = secB;
                bSections.Add(s);
                Odol.Set(target, "Sections", new TrackedArray<int>(target.Sections.Where(x => x != s)));
                continue;
            }
            Odol.Set(sec, "FaceUpperIndex", split);
            sections.Insert(s + 1, secB);
            foreach (var n in selections) ShiftSections(n, s, n == target ? null : s + 1);
            foreach (var p in Odol.RawProxies(lod).Cast<object>())
                if (Odol.Get<int>(p, "SectionIndex") > s) Odol.Set(p, "SectionIndex", Odol.Get<int>(p, "SectionIndex") + 1);
            for (int k = 0; k < bSections.Count; k++) bSections[k]++;
            bSections.Add(s + 1);
        }

        var inv = new int[perm.Length];
        for (int k = 0; k < perm.Length; k++) inv[perm[k]] = k;
        Odol.Set(typeof(Polygons), lod.Polygons, "Faces", perm.Select(k => faces[k]).ToArray());
        foreach (var n in selections)
            if (n.SelectedFaces?.Count > 0) Odol.Set(n, "SelectedFaces", new TrackedArray<int>(n.SelectedFaces.Select(f => inv[f]).OrderBy(f => f)));
        selections.Add(new NamedSelection(newSelection, true, bSections.OrderBy(s => s)));
        Odol.Set(typeof(LOD), lod, "Sections", sections.ToArray());
        lod.NamedSelections = selections.ToArray();
        Console.WriteLine($"{plan.Count} islands moved, {bSections.Count} sections on {newTexture} in '{newSelection}', {lod.Sections.Length} sections");
        Odol.Save(odol, output);
    }

    // Moves every section using a texture out of the given selections into a new selection.
    public static void MoveSections(string input, string output, string lodName, string texture, string newSelection, string[] from)
    {
        var odol = Odol.Load(input);
        var lod = Odol.FindLod(odol, lodName);
        var secs = Enumerable.Range(0, lod.Sections.Length)
            .Where(s => lod.Sections[s].TextureIndex >= 0 && lod.Textures[lod.Sections[s].TextureIndex].Equals(texture, StringComparison.OrdinalIgnoreCase)).ToList();
        if (secs.Count == 0) throw new Exception($"no sections use {texture}");
        foreach (var n in lod.NamedSelections.Where(n => from.Contains(n.Name, StringComparer.OrdinalIgnoreCase)))
            Odol.Set(n, "Sections", new TrackedArray<int>(n.Sections.Where(s => !secs.Contains(s))));
        lod.NamedSelections = lod.NamedSelections.Append(new NamedSelection(newSelection, true, secs)).ToArray();
        Console.WriteLine($"sections [{string.Join(',', secs)}] moved from [{string.Join(',', from)}] to '{newSelection}'");
        Odol.Save(odol, output);
    }

    // Writes one line per vertex: position, normal, S and T tangents, UV set 0.
    public static void DumpVertices(string input, string lodName, string output)
    {
        var lod = Odol.FindLod(Odol.Load(input), lodName);
        var uv = lod.UvSets[0].GetUV();
        using var w = new StreamWriter(output);
        for (int i = 0; i < lod.Vertices.Count; i++)
        {
            BIS.Core.Math.Vector3P p = lod.Vertices[i], n = lod.NormalsCompressed[i];
            var st = lod.STCoordsCompressed[i];
            BIS.Core.Math.Vector3P s = st.Item1, t = st.Item2;
            w.WriteLine(FormattableString.Invariant($"{p.X} {p.Y} {p.Z} {n.X} {n.Y} {n.Z} {s.X} {s.Y} {s.Z} {t.X} {t.Y} {t.Z} {uv[i].X} {uv[i].Y}"));
        }
        Console.WriteLine($"wrote {output}: {lod.Vertices.Count} vertices");
    }

    // Points every LOD's references to one texture at another, for replacement art shipped elsewhere.
    public static void Retexture(string input, string output, string from, string to)
    {
        var odol = Odol.Load(input);
        int n = 0;
        foreach (var lod in odol.Lods)
        {
            var t = lod.Textures.Select(x => x.Equals(from, StringComparison.OrdinalIgnoreCase) ? to : x).ToArray();
            n += t.Where((x, i) => x != lod.Textures[i]).Count();
            Odol.Set(typeof(LOD), lod, "Textures", t);
        }
        if (n == 0) throw new Exception($"no LOD uses {from}");
        Console.WriteLine($"{from} -> {to} in {n} LODs");
        Odol.Save(odol, output);
    }

    // Section indices after s move up by one; the new section s + 1 joins every selection holding s.
    static void ShiftSections(NamedSelection n, int s, int? join)
    {
        var list = n.Sections.Select(x => x > s ? x + 1 : x).ToList();
        if (join is int j && list.Contains(s)) list.Add(j);
        Odol.Set(n, "Sections", new TrackedArray<int>(list.OrderBy(x => x)));
    }

    static void SetAreaOverTex(Section s, float value)
    {
        var a = (float[])s.AreaOverTex.Clone();
        a[0] = value;
        Odol.Set(s, "AreaOverTex", a);
    }

    static float UvArea(Vector2[] uv, int[] f)
    {
        float a = 0;
        for (int i = 1; i + 1 < f.Length; i++)
        {
            Vector2 e1 = uv[f[i]] - uv[f[0]], e2 = uv[f[i + 1]] - uv[f[0]];
            a += Math.Abs(e1.X * e2.Y - e1.Y * e2.X) / 2;
        }
        return a;
    }

    // Compressed vectors hold three signed 10-bit components scaled by -1/511.
    static BIS.Core.Math.Vector3PCompressed Pack(float[] v, int o)
    {
        int C(float x) => (int)Math.Clamp(Math.Round(-x * 511), -511, 511) & 0x3FF;
        return new BIS.Core.Math.Vector3PCompressed(C(v[o]) | C(v[o + 1]) << 10 | C(v[o + 2]) << 20);
    }

    // ODOL v45+ stores UVs as 16-bit steps across [min, max]: u = 2^-16 * (q + 32767) * (max - min) + min.
    // q tops out at 32767, so max is widened to keep the largest UV representable.
    internal static void WriteUv(UVSet set, Vector2[] uv)
    {
        float minU = uv.Min(t => t.X), minV = uv.Min(t => t.Y);
        float maxU = minU + (uv.Max(t => t.X) - minU) * 65536f / 65534f, maxV = minV + (uv.Max(t => t.Y) - minV) * 65536f / 65534f;
        short Q(float x, float min, float max) => (short)Math.Clamp(Math.Round((x - min) / (max - min) * 65536.0 - 32767.0), -32767, 32767);
        var data = new byte[uv.Length * 4];
        for (int i = 0; i < uv.Length; i++)
        {
            BitConverter.TryWriteBytes(data.AsSpan(i * 4), Q(uv[i].X, minU, maxU));
            BitConverter.TryWriteBytes(data.AsSpan(i * 4 + 2), Q(uv[i].Y, minV, maxV));
        }
        Odol.Set(set, "MinU", minU); Odol.Set(set, "MinV", minV); Odol.Set(set, "MaxU", maxU); Odol.Set(set, "MaxV", maxV);
        Odol.Set(set, "UvData", new TrackedArray<byte>(data));
        if (set.DefaultFill) throw new Exception("UV set uses a default fill; not supported");
    }
}
