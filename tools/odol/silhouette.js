// node silhouette.js <model.obj> <out.png> [--clip geometry.obj] [--points points.json]
// Renders a flat top-view silhouette for a pylon-loadout uiPicture, in the vanilla style: 2048x1024,
// nose left, dark grey on transparent. Takes ODOL model coordinates from `odol export-obj`, where the
// nose is at -Z and the right wing at -X.
// --clip drops faces outside another LOD's footprint, such as the drag chute and afterburner flames
// in a visual LOD; export the Geometry LOD for it.
// --points ([{ "name", "x", "y", "z" }], ODOL coordinates) prints the UIposition of each point:
// the Eden pylon dialog maps UIposition x 0..0.75 and y 0..0.5 across the picture.
const fs = require('fs'), zlib = require('zlib');
const [, , objFile, outFile, ...rest] = process.argv;
const opt = name => { const i = rest.indexOf(name); return i < 0 ? null : rest[i + 1]; };
const pointsFile = opt('--points'), clipFile = opt('--clip');
const W = 2048, H = 1024, SS = 3, FILL = 0.95, COLOUR = [64, 66, 64];

function readObj(file) {
  const verts = [], faces = [];
  for (const line of fs.readFileSync(file, 'utf8').split(/\r?\n/)) {
    const p = line.split(' ');
    if (p[0] === 'v') verts.push([+p[1], +p[2], +p[3]]);
    else if (p[0] === 'f') faces.push(p.slice(1).map(i => parseInt(i, 10) - 1));
  }
  return { verts, faces };
}
const { verts, faces: allFaces } = readObj(objFile);
let faces = allFaces;
if (clipFile) {
  const c = readObj(clipFile).verts, M = 0.1;
  const lo = [0, 2].map(k => Math.min(...c.map(v => v[k])) - M), hi = [0, 2].map(k => Math.max(...c.map(v => v[k])) + M);
  faces = allFaces.filter(f => f.every(i => [0, 2].every((k, j) => verts[i][k] >= lo[j] && verts[i][k] <= hi[j])));
}

// Top view: image x follows the model Z axis (nose left), image y follows model X (right wing up).
const used = [...new Set(faces.flat())].map(i => verts[i]);
const [minZ, maxZ] = [Math.min(...used.map(v => v[2])), Math.max(...used.map(v => v[2]))];
const [minX, maxX] = [Math.min(...used.map(v => v[0])), Math.max(...used.map(v => v[0]))];
const scale = Math.min((W * FILL) / (maxZ - minZ), (H * FILL) / (maxX - minX));
const cz = (minZ + maxZ) / 2, cx = (minX + maxX) / 2;
const toImage = (x, z) => [W / 2 + (z - cz) * scale, H / 2 + (x - cx) * scale];

// Supersampled coverage mask, filled triangle by triangle.
const sw = W * SS, sh = H * SS, mask = new Uint8Array(sw * sh);
function fill(a, b, c) {
  const x0 = Math.max(0, Math.floor(Math.min(a[0], b[0], c[0]))), x1 = Math.min(sw - 1, Math.ceil(Math.max(a[0], b[0], c[0])));
  const y0 = Math.max(0, Math.floor(Math.min(a[1], b[1], c[1]))), y1 = Math.min(sh - 1, Math.ceil(Math.max(a[1], b[1], c[1])));
  const area = (b[0] - a[0]) * (c[1] - a[1]) - (b[1] - a[1]) * (c[0] - a[0]);
  if (Math.abs(area) < 1e-9) return;
  for (let y = y0; y <= y1; y++) {
    for (let x = x0; x <= x1; x++) {
      const px = x + 0.5, py = y + 0.5;
      const w0 = (b[0] - px) * (c[1] - py) - (b[1] - py) * (c[0] - px);
      const w1 = (c[0] - px) * (a[1] - py) - (c[1] - py) * (a[0] - px);
      const w2 = (a[0] - px) * (b[1] - py) - (a[1] - py) * (b[0] - px);
      if ((w0 >= 0 && w1 >= 0 && w2 >= 0) || (w0 <= 0 && w1 <= 0 && w2 <= 0)) mask[y * sw + x] = 1;
    }
  }
}
for (const f of faces) {
  const p = f.map(i => toImage(verts[i][0], verts[i][2]).map(v => v * SS));
  for (let i = 1; i + 1 < p.length; i++) fill(p[0], p[i], p[i + 1]);
}

// Downsample to RGBA rows, each prefixed with filter type 0, and write a PNG.
const raw = Buffer.alloc(H * (W * 4 + 1));
for (let y = 0; y < H; y++) {
  const row = y * (W * 4 + 1);
  for (let x = 0; x < W; x++) {
    let n = 0;
    for (let j = 0; j < SS; j++) for (let i = 0; i < SS; i++) n += mask[(y * SS + j) * sw + x * SS + i];
    raw.set([...COLOUR, Math.round((255 * n) / (SS * SS))], row + 1 + x * 4);
  }
}
const crcTable = Array.from({ length: 256 }, (_, n) => { let c = n; for (let k = 0; k < 8; k++) c = c & 1 ? 0xedb88320 ^ (c >>> 1) : c >>> 1; return c >>> 0; });
const crc = b => { let c = 0xffffffff; for (const x of b) c = crcTable[(c ^ x) & 0xff] ^ (c >>> 8); return (c ^ 0xffffffff) >>> 0; };
const chunk = (type, data) => {
  const t = Buffer.concat([Buffer.from(type, 'latin1'), data]);
  const len = Buffer.alloc(4); len.writeUInt32BE(data.length);
  const sum = Buffer.alloc(4); sum.writeUInt32BE(crc(t));
  return Buffer.concat([len, t, sum]);
};
const ihdr = Buffer.alloc(13);
ihdr.writeUInt32BE(W, 0); ihdr.writeUInt32BE(H, 4); ihdr.set([8, 6, 0, 0, 0], 8);
fs.writeFileSync(outFile, Buffer.concat([Buffer.from([137, 80, 78, 71, 13, 10, 26, 10]), chunk('IHDR', ihdr), chunk('IDAT', zlib.deflateSync(raw)), chunk('IEND', Buffer.alloc(0))]));
console.log(`wrote ${outFile}: ${faces.length} faces, ${scale.toFixed(1)} px/m`);

if (pointsFile) {
  for (const p of JSON.parse(fs.readFileSync(pointsFile, 'utf8'))) {
    const [ix, iy] = toImage(p.x, p.z);
    console.log(`${p.name}: UIposition[] = { ${((ix / W) * 0.75).toFixed(3)}, ${((iy / H) * 0.5).toFixed(3)} };`);
  }
}
