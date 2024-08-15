#define f first
#define s second

int uf[MAX];
vector<pair<int, pair<int, int>>> edgs; //(cost (u, v))

int Find(int i){return (uf[i]<0)? i : uf[i] = Find(uf[i]);}

bool Union(int i, int j){
    i = Find(i), j = Find(j);
    if(i == j) return 0;
    if(uf[i]>uf[j]) swap(i, j);
    uf[i]+=uf[j], uf[j]=i;
    return 1;
}

int kruskal(){
    sort(edgs.begin(), edgs.end());
    memset(uf, -1, sizeof(uf));
    int mst = 0;
    for(auto &p : edgs) if(Union(p.s.f, p.s.s)) mst += p.f;
    return mst;
}

