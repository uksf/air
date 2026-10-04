using System.Globalization;
using System.Numerics;
using BIS.P3D.ODOL;

const string Usage = """
odol - inspect and edit binarized (ODOL) Arma 3 models

Inspect:
  info       <model>                       LODs with vertex, face, selection and proxy counts
  proxies    <model> [filter]              proxies per LOD: id, selection, position and axes
  points     <model> <lod>                 named selections with vertex count and first vertex
  verts      <model> <lod>                 every vertex in a LOD
  dump       <model> <lod>                 raw LOD, section, polygon and UV set fields
  materials  <model> <lod>                 embedded materials with their stage textures
  anims      <model> [filter]              model animations: type, source, phase and value range
  bones      <model> <lod> [filter]        bones with the vertices they move and the animations driving them
  selection  <model> <lod> <name>          a selection's sections, textures, vertex extent and bone weights
  sections   <model> <lod> [x0 x1 y0 y1 z0 z1]
                                           sections with texture, extent and bones, optionally inside a box
  roundtrip  <model>                       read and re-write in memory; reports differing bytes
  vertices   <model> <lod> <out.txt>         per vertex: position, normal, S and T tangents, UV
  export-obj <model> <lod> <out.obj>       write a LOD as Wavefront OBJ with UVs, one usemtl per section texture

Edit (each output is re-read and must serialize to the same bytes):
  set-source   <in> <out> <anim> <source> [clamp|mirror|loop]
                                           point an animation at another source, optionally its address
  bind         <in> <out> <lod> <selection|#section> <bone> [x0 x1 y0 y1 z0 z1]
                                           weight unweighted faces (optionally only those inside a box) to a bone
  remap        <in> <out> <rule>...        rule = oldModel|oldId|newModel|newId; @file reads rules, one per line
  add-proxies  <in> <out> <template> <filter>
                                           copy LOD 0 proxies matching filter into the memory LOD
  add-point    <in> <out> <template> <name> <x> <y> <z> [like]
                                           add a named memory point, optionally weighted like a selection
  add-physx    <in> <out> <mass kg>      clone the geometry LOD as a PhysX LOD and set the model mass
  cut-seams    <in> <out> <lod> <cuts.json>            duplicate vertices so listed faces get their own copies (UV seams)
  uv-split     <in> <out> <lod> <plan.json> <selection> <new-selection> <new-texture>
                                           move UV islands per plan; sheet-B faces get new sections and selection
  move-sections <in> <out> <lod> <texture> <new-selection> <from,from>
                                           move every section using texture out of selections into a new one
  retexture    <in> <out> <old-texture> <new-texture>
                                           point every LOD's use of a texture at another path

<lod> is a resolution (0, 1100, 1e15) or memory, geometry, landcontact, roadway, fire, pilot.
<template> is a model whose memory LOD has proxy triangles and points, such as the A-143 Buzzard.
""";

var help = args.Length > 0 && args[0] is "-h" or "--help" or "help";
if (help || args.Length < 2)
{
    Console.Write(Usage);
    return help ? 0 : 2;
}

var cmd = args[0];
var input = args[1];

string Vec(Matrix4x4 m) => $"[{m.M41:F2},{m.M42:F2},{m.M43:F2}]";

string Describe(object v)
{
    if (v == null) return "null";
    if (v is string str) return "'" + str + "'";
    if (v is System.Collections.IEnumerable e)
    {
        var items = e.Cast<object>().ToList();
        var head = string.Join(", ", items.Take(4).Select(x => x is System.Collections.IEnumerable && x is not string ? "[..]" : x?.ToString()));
        return $"len {items.Count} [{head}{(items.Count > 4 ? ", .." : "")}]";
    }
    return v.ToString();
}

void Dump(object o, string indent)
{
    foreach (var p in o.GetType().GetProperties(Odol.Any))
    {
        if (p.GetIndexParameters().Length > 0) continue;
        object v;
        try { v = p.GetValue(o); } catch { continue; }
        Console.WriteLine($"{indent}{p.Name}: {Describe(v)}");
    }
}

IEnumerable<string> Rules(IEnumerable<string> a) =>
    a.SelectMany(r => r.StartsWith('@') ? File.ReadAllLines(r[1..]).Select(l => l.Trim()).Where(l => l.Length > 0 && !l.StartsWith('#')) : new[] { r });

void Need(int n)
{
    if (args.Length < n) throw new ArgumentException($"{cmd} needs {n - 1} arguments; run odol --help");
}

try
{
    switch (cmd)
    {
        case "info":
        {
            var odol = Odol.Load(input);
            Console.WriteLine($"{input}: ODOL v{odol.Version}, {odol.Lods.Length} LODs");
            var mi = odol.ModelInfo;
            Console.WriteLine(FormattableString.Invariant($"  mass {mi.Mass} kg, centre of mass [{mi.CenterOfMass.X}, {mi.CenterOfMass.Y}, {mi.CenterOfMass.Z}], {mi.MassArray?.Length ?? 0} geometry point masses"));
            Console.WriteLine($"  special LODs: geometry {mi.Geometry}, geometryPhys {mi.GeometryPhys}, geometrySimple {mi.GeometrySimple}, memory {mi.Memory}, fire {mi.GeometryFire}, view {mi.GeometryView}, landContact {mi.LandContact}");
            foreach (var lod in odol.Lods)
                Console.WriteLine($"  {lod.Resolution.ToString("G6", CultureInfo.InvariantCulture),-8} vertices {lod.Vertices.Count,6} faces {lod.Polygons.Faces.Length,6} sections {lod.Sections.Length,3} selections {lod.NamedSelections.Length,4} proxies {Odol.RawProxies(lod).Length,3}");
            break;
        }
        case "proxies":
        {
            var filter = args.Length > 2 ? args[2] : "";
            foreach (var lod in Odol.Load(input).Lods)
            {
                var raw = Odol.RawProxies(lod);
                if (raw.Length == 0) continue;
                Console.WriteLine($"LOD {lod.Resolution:G6}: {raw.Length} proxies");
                foreach (var p in raw)
                {
                    var name = Odol.Get<string>(p, "ProxyModel");
                    if (!name.Contains(filter, StringComparison.OrdinalIgnoreCase)) continue;
                    var mx = Odol.Get<BIS.Core.Math.Matrix4P>(p, "Transformation").Matrix;
                    Console.WriteLine($"  {Odol.Get<int>(p, "SequenceID"),3} sel={Odol.Get<int>(p, "NamedSelectionIndex"),3} bone={Odol.Get<int>(p, "BoneIndex"),3} sec={Odol.Get<int>(p, "SectionIndex"),3} {name} pos={Vec(mx)} y=[{mx.M21:F2},{mx.M22:F2},{mx.M23:F2}] z=[{mx.M31:F2},{mx.M32:F2},{mx.M33:F2}]");
                }
            }
            break;
        }
        case "points":
        {
            Need(3);
            var lod = Odol.FindLod(Odol.Load(input), args[2]);
            foreach (var ns in lod.NamedSelections)
            {
                var v = ns.SelectedVertices.ToArray();
                Console.WriteLine($"{ns.Name} n={v.Length} {(v.Length > 0 ? lod.Vertices[v[0]].ToString() : "")}");
            }
            break;
        }
        case "verts":
        {
            Need(3);
            var lod = Odol.FindLod(Odol.Load(input), args[2]);
            for (int i = 0; i < lod.Vertices.Count; i++) Console.WriteLine($"v{i} {lod.Vertices[i]}");
            break;
        }
        case "materials":
        {
            Need(3);
            var lod = Odol.FindLod(Odol.Load(input), args[2]);
            for (int m = 0; m < lod.Materials.Length; m++)
            {
                var mat = lod.Materials[m];
                Console.WriteLine($"{m} {mat.MaterialName} ps={mat.PixelShader}");
                for (int s = 0; s < mat.StageTextures.Length; s++)
                    Console.WriteLine($"    stage {s}: '{mat.StageTextures[s].Texture}' uvSource={(s < mat.StageTransforms.Length ? mat.StageTransforms[s].UvSource : 0)}");
            }
            break;
        }
        case "dump":
        {
            Need(3);
            var lod = Odol.FindLod(Odol.Load(input), args[2]);
            Dump(lod, "");
            var lli = typeof(LOD).GetProperty("LoadableLodInfo", Odol.Any).GetValue(lod);
            if (lli != null) { Console.WriteLine("-- LoadableLodInfo:"); Dump(lli, "  "); }
            var i = 0;
            foreach (var sec in lod.Sections) { Console.WriteLine($"-- Section {i++}:"); Dump(sec, "  "); }
            Console.WriteLine("-- Polygons:");
            Dump(lod.Polygons, "  ");
            Console.WriteLine("   first faces: " + string.Join(" ", lod.Polygons.Faces.Take(6).Select(f => "(" + string.Join(",", f.VertexIndices) + ")")));
            var u = 0;
            foreach (var uv in lod.UvSets) { Console.WriteLine($"-- UvSet {u++}:"); Dump(uv, "  "); }
            break;
        }
        case "anims":
        {
            var filter = args.Length > 2 ? args[2] : "";
            var model = Odol.Load(input);
            var classes = model.Animations?.AnimationClasses ?? [];
            for (int k = 0; k < classes.Length; k++)
            {
                var a = classes[k];
                // LODs in which the animation drives a bone; an animation bound in none never moves.
                var bound = model.Lods.Where((l, j) => model.Animations.Anims2Bones[j][k] >= 0).Select(l => l.Resolution.ToString("G3", CultureInfo.InvariantCulture));
                if (!a.AnimName.Contains(filter, StringComparison.OrdinalIgnoreCase) && !a.AnimSource.Contains(filter, StringComparison.OrdinalIgnoreCase)) continue;
                // Source address: 0 clamp, 1 mirror, 2 loop.
                var range = a.AnimType switch
                {
                    <= 3 => $" angle {a.Angle0 * 180 / MathF.PI:G4}..{a.Angle1 * 180 / MathF.PI:G4} deg",
                    <= 7 => $" offset {a.Offset0:G4}..{a.Offset1:G4}",
                    9 => $" hide at {a.HideValue:G4}",
                    _ => "",
                };
                Console.WriteLine($"{a.AnimName,-32} source {a.AnimSource,-20} type {a.AnimType} address {a.SourceAddress} value {a.MinValue:G4}..{a.MaxValue:G4}{range} bones in LOD {string.Join(',', bound)}");
            }
            break;
        }
        case "bind":
            Need(6);
            Selections.Bind(input, args[2], args[3], args[4], args[5], args.Length >= 12 ? args.Skip(6).Take(6).Select(Odol.ParseFloat).ToArray() : null);
            break;
        case "sections":
            Need(3);
            Selections.ListSections(input, args[2], args.Length >= 9 ? args.Skip(3).Take(6).Select(Odol.ParseFloat).ToArray() : null);
            break;
        case "selection":
            Need(4);
            Selections.Show(input, args[2], args[3]);
            break;
        case "bones":
            Need(3);
            Bones.List(input, args[2], args.Length > 3 ? args[3] : "");
            break;
        case "set-source":
            Need(5);
            Edits.SetSource(input, args[2], args[3], args[4], args.Length > 5 ? args[5] : null);
            break;
        case "cut-seams":
            Need(5);
            Seams.Cut(input, args[2], args[3], args[4]);
            break;
        case "uv-split":
            Need(8);
            Uv.Split(input, args[2], args[3], args[4], args[5], args[6], args[7]);
            break;
        case "move-sections":
            Need(7);
            Uv.MoveSections(input, args[2], args[3], args[4], args[5], args[6].Split(','));
            break;
        case "vertices":
            Need(4);
            Uv.DumpVertices(input, args[2], args[3]);
            break;
        case "retexture":
            Need(5);
            Uv.Retexture(input, args[2], args[3], args[4]);
            break;
        case "export-obj":
            Need(4);
            Edits.ExportObj(input, args[2], args[3]);
            break;
        case "roundtrip":
        {
            var (inLen, outLen, diffs, first) = Odol.Roundtrip(input);
            Console.WriteLine($"in {inLen} bytes, out {outLen} bytes, {diffs} differing bytes{(first >= 0 ? $", first at {first}" : "")}");
            return inLen == outLen && diffs == 0 ? 0 : 1;
        }
        case "remap":
            Need(4);
            Edits.Remap(input, args[2], Rules(args.Skip(3)));
            break;
        case "add-proxies":
            Need(5);
            Edits.AddMemoryProxies(input, args[2], args[3], args[4]);
            break;
        case "add-point":
            Need(8);
            Edits.AddPoint(input, args[2], args[3], args[4], new Vector3(Odol.ParseFloat(args[5]), Odol.ParseFloat(args[6]), Odol.ParseFloat(args[7])), args.Length > 8 ? args[8] : null);
            break;
        case "add-physx":
            Need(4);
            Physx.Add(input, args[2], Odol.ParseFloat(args[3]));
            break;
        default:
            Console.Error.WriteLine($"unknown command {cmd}");
            Console.Write(Usage);
            return 2;
    }
    return 0;
}
catch (Exception e) when (e is not OutOfMemoryException)
{
    var inner = e is System.Reflection.TargetInvocationException t ? t.InnerException : e;
    Console.Error.WriteLine(Environment.GetEnvironmentVariable("ODOL_DEBUG") is null ? $"error: {inner.Message}" : $"error: {inner}");
    return 1;
}
