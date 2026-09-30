using System.Globalization;
using System.Reflection;
using BIS.Core.Streams;
using BIS.P3D;
using BIS.P3D.ODOL;

// Loading, saving and reflection helpers over BIS.P3D's ODOL object graph.
// BIS.P3D keeps several members private or get-only; they are reached by name, which is why the
// UKSFTA-BIS commit is pinned in build.sh.
static class Odol
{
    public const BindingFlags Any = BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Instance;

    static readonly Dictionary<string, float> LodAliases = new(StringComparer.OrdinalIgnoreCase)
    {
        ["memory"] = 1e15f,
        ["landcontact"] = 2e15f,
        ["roadway"] = 3e15f,
        ["geometry"] = 1e13f,
        ["fire"] = 7e15f,
        ["pilot"] = 1100f,
    };

    public static ODOL Load(string path)
    {
        P3D model;
        // The LOD reader traces every section to stderr.
        var err = Console.Error;
        Console.SetError(TextWriter.Null);
        try
        {
            using var s = File.OpenRead(path);
            model = new P3D(s);
        }
        finally
        {
            Console.SetError(err);
        }
        return typeof(P3D).GetField("binarized", Any).GetValue(model) as ODOL
            ?? throw new Exception($"{path} is not a binarized (ODOL) model");
    }

    static byte[] Serialize(ODOL odol)
    {
        using var m = new MemoryStream();
        var w = new BinaryWriterEx(m);
        odol.Write(w);
        w.Flush();
        return m.ToArray();
    }

    // Writes the model, then reloads it and checks it serializes to the same bytes.
    // A failure here means the edit left the object graph inconsistent.
    public static void Save(ODOL odol, string path)
    {
        var bytes = Serialize(odol);
        File.WriteAllBytes(path, bytes);
        if (!Serialize(Load(path)).AsSpan().SequenceEqual(bytes)) throw new Exception($"{path} does not re-read byte-stably");
        Console.WriteLine($"wrote {path} ({bytes.Length} bytes, re-reads byte-stably)");
    }

    // Byte-level roundtrip of an unedited model: proves the reader and writer handle this file.
    public static (int inLen, int outLen, int diffs, int first) Roundtrip(string path)
    {
        var a = File.ReadAllBytes(path);
        var b = Serialize(Load(path));
        int diffs = 0, first = -1;
        for (int i = 0; i < Math.Min(a.Length, b.Length); i++)
        {
            if (a[i] == b[i]) continue;
            diffs++;
            if (first < 0) first = i;
        }
        return (a.Length, b.Length, diffs, first);
    }

    public static float ParseFloat(string s) => float.Parse(s, CultureInfo.InvariantCulture);

    public static LOD FindLod(ODOL odol, string res)
    {
        var r = LodAliases.TryGetValue(res, out var alias) ? alias : ParseFloat(res);
        return odol.Lods.FirstOrDefault(l => Math.Abs(l.Resolution - r) <= Math.Abs(r) * 1e-5f)
            ?? throw new Exception($"no LOD {res}; have {string.Join(", ", odol.Lods.Select(l => l.Resolution.ToString("G6", CultureInfo.InvariantCulture)))}");
    }

    public static Array RawProxies(LOD lod) => (Array)typeof(LOD).GetProperty("RawProxies", Any).GetValue(lod);

    public static T Get<T>(object o, string prop) => (T)o.GetType().GetProperty(prop, Any).GetValue(o);

    public static object Clone(object o) => typeof(object).GetMethod("MemberwiseClone", Any).Invoke(o, null);

    // Get-only auto properties are set through their compiler-generated backing fields.
    public static void Set(object o, string prop, object value) => Set(o.GetType(), o, prop, value);

    public static void Set(Type t, object o, string prop, object value) =>
        t.GetField($"<{prop}>k__BackingField", Any).SetValue(o, value);

    public static List<object> BoneRefs(LOD lod) =>
        ((System.Collections.IEnumerable)typeof(LOD).GetProperty("VertexBoneRef", Any).GetValue(lod)).Cast<object>().ToList();

    public static void SetBoneRefs(LOD lod, List<object> refs)
    {
        var type = refs[0].GetType();
        var array = Array.CreateInstance(type, refs.Count);
        for (int i = 0; i < refs.Count; i++) array.SetValue(refs[i], i);
        Set(typeof(LOD), lod, "VertexBoneRef", Activator.CreateInstance(typeof(BIS.Core.TrackedArray<>).MakeGenericType(type), array));
    }
}
