import math, collections
def load(fn):
    V=[];T=[];F=[];sec=None;mat=None
    for l in open(fn):
        p=l.split()
        if not p: continue
        if p[0]=='v': V.append(tuple(map(float,p[1:4])))
        elif p[0]=='vt': T.append(tuple(map(float,p[1:3])))
        elif p[0]=='g': sec=int(p[1][1:])
        elif p[0]=='usemtl': mat=p[1].replace(chr(92),'/').split('/')[-1]
        elif p[0]=='f': F.append(dict(sec=sec,mat=mat,v=[int(x.split('/')[0])-1 for x in p[1:]]))
    return V,T,F
def tris(f):
    for i in range(1,len(f)-1): yield f[0],f[i],f[i+1]
def area3(a,b,c):
    u=[b[i]-a[i] for i in range(3)];v=[c[i]-a[i] for i in range(3)]
    x=(u[1]*v[2]-u[2]*v[1],u[2]*v[0]-u[0]*v[2],u[0]*v[1]-u[1]*v[0]);return 0.5*math.sqrt(sum(k*k for k in x)),x
def area2(a,b,c): return 0.5*abs((b[0]-a[0])*(c[1]-a[1])-(c[0]-a[0])*(b[1]-a[1]))
def islands(V,T,F,pred):
    par={}
    def find(x):
        par.setdefault(x,x)
        while par[x]!=x: par[x]=par[par[x]]; x=par[x]
        return x
    idx=[i for i,f in enumerate(F) if pred(f)]
    for i in idx:
        for v in F[i]['v'][1:]: par[find(v)]=find(F[i]['v'][0])
    # duplicates split only for normals share position and UV: same UV island
    seen={}
    for i in idx:
        for v in F[i]['v']:
            k=(round(V[v][0],3),round(V[v][1],3),round(V[v][2],3),round(T[v][0],4),round(T[v][1],4))
            if k in seen: par[find(v)]=find(seen[k])
            else: seen[k]=v
    comp=collections.defaultdict(list)
    for i in idx: comp[find(F[i]['v'][0])].append(i)
    out=[]
    for fs in comp.values():
        up=dn=A=U=0
        for i in fs:
            for a,b,c in tris(F[i]['v']):
                ar,n=area3(V[a],V[b],V[c]); A+=ar; U+=area2(T[a],T[b],T[c])
                L=math.sqrt(sum(k*k for k in n)) or 1
                if n[1]/L>0.5: up+=ar
                elif n[1]/L<-0.5: dn+=ar
        vs=sorted({v for i in fs for v in F[i]['v']})
        us=[T[v] for v in vs]
        out.append(dict(faces=fs,verts=vs,A=A,U=U,up=up,dn=dn,secs=sorted({F[i]['sec'] for i in fs}),
            box=(min(u[0] for u in us),min(u[1] for u in us),max(u[0] for u in us),max(u[1] for u in us))))
    return out
