using System.Reflection;
using BIS.Core.Math;
using BIS.Core.Streams;
using BIS.P3D.ODOL;

// Gives a model a PhysX geometry LOD (resolution 4e13) cloned from its collision geometry (1e13), as the
// vanilla jets have. Without one the engine builds no physics body: the vehicle reports no mass and
// ignores addForce/addTorque. Also sets the model mass the body gets.
static class Physx
{
    const float GeometryRes = 1e13f, PhysxRes = 4e13f;
    const BindingFlags Any = BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Instance;

    // BIS.P3D's names for the special-LOD index bytes; they sit one field off the engine's meaning
    // (checked against the A-143 and F/A-181), so "Geometry" here is the PhysX LOD.
    static readonly string[] SpecialLods = {
        "GeometrySimple", "GeometryPhys", "Memory", "Geometry", "GeometryFire", "GeometryView",
        "GeometryViewPilot", "GeometryViewGunner", "GeometryViewCargo", "LandContact", "Roadway", "Paths", "Hitpoints" };

    public static void Add(string input, string output, float mass)
    {
        var odol = Odol.Load(input);
        if (odol.Lods.Any(l => l.Resolution == PhysxRes)) throw new Exception("model already has a PhysX LOD");
        int g = Array.FindIndex(odol.Lods, l => l.Resolution == GeometryRes);
        if (g < 0) throw new Exception("model has no geometry LOD");
        int at = g + 1;

        // clone the geometry LOD through its own writer and reader
        var src = odol.Lods[g];
        var info = typeof(LOD).GetProperty("LoadableLodInfo", Any).GetValue(src);
        using var m = new MemoryStream();
        var w = new BinaryWriterEx(m) { UseLZOCompression = true, UseCompressionFlag = true };
        typeof(LOD).GetMethod("Write", Any).Invoke(src, new object[] { w, odol.Version });
        w.Flush(); m.Position = 0;
        var r = new BinaryReaderEx(m) { UseLZOCompression = true, UseCompressionFlag = true };
        var ctor = typeof(LOD).GetConstructors(Any).Single(c => c.GetParameters().Length == 4);
        var clone = (LOD)ctor.Invoke(new object[] { r, PhysxRes, info, (int)odol.Version });
        Odol.Set(typeof(ODOL), odol, "Lods", odol.Lods.Take(at).Append(clone).Concat(odol.Lods.Skip(at)).ToArray());

        var mi = odol.ModelInfo;
        foreach (var name in SpecialLods)
        {
            byte v = Odol.Get<byte>(mi, name);
            if (v != 255 && v >= at) Odol.Set(mi, name, (byte)(v + 1));
        }
        Odol.Set(mi, "Geometry", (byte)at);
        byte minShadow = Odol.Get<byte>(mi, "MinShadow");
        if (minShadow != 255 && minShadow >= at) Odol.Set(mi, "MinShadow", (byte)(minShadow + 1));
        foreach (var name in new[] { "PreferredShadowVolumeLod", "PreferredShadowBufferLod", "PreferredShadowBufferLodVis" })
        {
            var a = Odol.Get<int[]>(mi, name);
            if (a == null) continue;
            var shifted = a.Select(x => x >= at ? x + 1 : x).ToList();
            shifted.Insert(at, -1);
            Odol.Set(mi, name, shifted.ToArray());
        }

        // the clone keeps the geometry LOD's bones, so it takes its animation tables too
        var an = odol.Animations;
        if (an != null)
        {
            Odol.Set(an, "Bones2Anims", Insert(an.Bones2Anims, at, an.Bones2Anims[g]));
            Odol.Set(an, "Anims2Bones", Insert(an.Anims2Bones, at, (int[])an.Anims2Bones[g].Clone()));
            Odol.Set(an, "AxisData", Insert(an.AxisData, at, (Vector3P[][])an.AxisData[g].Clone()));
        }

        float old = mi.Mass;
        Odol.Set(mi, "Mass", mass);
        Odol.Set(mi, "InvMass", 1 / mass);
        var inv = Odol.Get<Vector3P[]>(mi, "InvInertia");
        if (inv != null && old > 0)
            Odol.Set(mi, "InvInertia", inv.Select(v => new Vector3P(v.X * old / mass, v.Y * old / mass, v.Z * old / mass)).ToArray());

        Console.WriteLine($"PhysX LOD {at} cloned from geometry LOD {g} ({src.Vertices.Count} vertices); mass {old} -> {mass} kg");
        Odol.Save(odol, output);
    }

    static T[] Insert<T>(T[] a, int at, T item) => a.Take(at).Append(item).Concat(a.Skip(at)).ToArray();
}
