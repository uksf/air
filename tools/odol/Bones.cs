using System.Globalization;
using BIS.P3D.ODOL;

// Which geometry each skeleton bone moves in a LOD, and which animations drive the bone. An animation
// that turns but moves nothing visible is usually bound to a bone with no, or the wrong, vertices.
static class Bones
{
    public static void List(string input, string lodName, string filter)
    {
        var odol = Odol.Load(input);
        var lod = Odol.FindLod(odol, lodName);
        int lodIndex = Array.IndexOf(odol.Lods, lod);
        var skeleton = Odol.Get<ModelInfo>(odol, "ModelInfo").Skeleton;
        var names = skeleton.SkeletonBoneNames.Select(b => b.BoneName).ToArray();
        var subToBone = lod.SubSkeletonsToSkeleton;

        // Each vertex carries up to four (sub-skeleton index, weight) byte pairs.
        var refs = Odol.BoneRefs(lod);
        var perSub = new Dictionary<int, List<int>>();
        for (int v = 0; v < refs.Count; v++)
        {
            int count = Odol.Get<int>(refs[v], "Count");
            var data = Odol.Get<byte[]>(refs[v], "Data");
            for (int i = 0; i < Math.Min(count, 4); i++)
            {
                if (!perSub.TryGetValue(data[i * 2], out var list)) perSub[data[i * 2]] = list = new List<int>();
                list.Add(v);
            }
        }

        var anims = odol.Animations?.AnimationClasses ?? [];
        var bound = odol.Animations?.Anims2Bones[lodIndex] ?? [];
        for (int s = 0; s < subToBone.Length; s++)
        {
            var name = names[subToBone[s]];
            var driving = Enumerable.Range(0, anims.Length).Where(k => bound[k] == subToBone[s]).Select(k => $"{anims[k].AnimName}({anims[k].AnimSource})").ToList();
            if (filter.Length > 0 && !name.Contains(filter, StringComparison.OrdinalIgnoreCase) && !driving.Any(d => d.Contains(filter, StringComparison.OrdinalIgnoreCase))) continue;
            var verts = perSub.GetValueOrDefault(s) ?? new List<int>();
            string where = "";
            if (verts.Count > 0)
            {
                var p = verts.Select(v => lod.Vertices[v]).ToList();
                string R(Func<BIS.Core.Math.Vector3P, float> f) => string.Create(CultureInfo.InvariantCulture, $"{p.Min(f):F2}..{p.Max(f):F2}");
                where = $" x {R(q => q.X)} y {R(q => q.Y)} z {R(q => q.Z)}";
            }
            Console.WriteLine($"{s,3} {name,-28} vertices {verts.Count,5}{where} anims [{string.Join(", ", driving)}]");
        }
    }
}
