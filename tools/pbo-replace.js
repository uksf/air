// node pbo-replace.js <in.pbo> <out.pbo> <entry name> <new file>
// Rebuilds a PBO with one uncompressed entry replaced. Header properties, entry order and timestamps
// are kept and the SHA1 trailer is recomputed. The output is unsigned.
const fs = require('fs'), crypto = require('crypto');
const [, , inp, out, entryName, newFile] = process.argv;
const b = fs.readFileSync(inp);
let o = 0;
const cstr = () => { const e = b.indexOf(0, o); const s = b.toString('latin1', o, e); o = e + 1; return s; };
const headerStart = o;
const entries = [];
let props = null;
for (;;) {
  const name = cstr();
  const f = [0, 1, 2, 3, 4].map(i => b.readUInt32LE(o + i * 4)); o += 20;
  if (props === null && f[0] === 0x56657273 && name === '') {
    const ps = o; while (cstr() !== '') {} props = b.subarray(ps, o); continue;
  }
  if (props === null) props = Buffer.alloc(0);
  if (name === '') break;
  entries.push({ name, mime: f[0], orig: f[1], reserved: f[2], time: f[3], size: f[4] });
}
let data = o;
for (const e of entries) { e.data = b.subarray(data, data + e.size); data += e.size; }
const target = entries.find(e => e.name.toLowerCase() === entryName.toLowerCase());
if (!target) throw new Error('entry not found: ' + entryName);
if (target.mime !== 0) throw new Error('compressed entry');
target.data = fs.readFileSync(newFile); target.size = target.data.length; target.orig = 0;
const z = s => Buffer.from(s + '\0', 'latin1');
const u32 = (...v) => { const x = Buffer.alloc(4 * v.length); v.forEach((n, i) => x.writeUInt32LE(n >>> 0, i * 4)); return x; };
const parts = [z(''), u32(0x56657273, 0, 0, 0, 0), props];
for (const e of entries) parts.push(z(e.name), u32(e.mime, e.orig, e.reserved, e.time, e.size));
parts.push(z(''), u32(0, 0, 0, 0, 0));
for (const e of entries) parts.push(e.data);
const body = Buffer.concat(parts);
fs.writeFileSync(out, Buffer.concat([body, Buffer.from([0]), crypto.createHash('sha1').update(body).digest()]));
console.log(`replaced ${target.name} (${target.size} bytes); ${entries.length} entries; out ${body.length + 21} bytes`);
