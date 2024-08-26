pair<int, int> G[MAX];
int n, in_deg[MAX], out_deg[MAX];
stack<int> path;

bool Eulerian(){
    int stV = 0, endV = 0;
    for(int i = 0; i<n; ++i){
        if(abs(in_deg[i]-out_deg[i]) > 1) return 0;
        stV+=(out_deg[i]-in_deg[i]==1);
        endV+=(in_deg[i]-out_deg[i]==1);
    }return !(stV+endV) || (stV+endV == 2);
}

int stV(){
    int stV = 0;
    for(int i = 0; i<n; ++i){
        if(out_deg[i]-in_deg[i]==1) return i;
        if(out_deg[i]) stV = i;
    }return stV;
}

void dfs(int i){
    while(out_deg[i]){
        int nx = G[i].back(); G[i].pop_back();
        --out_deg[i];
        dfs(nx);
    }path.push(i);
}

//if graph has eulerian path or circuit it will be stored in path
void FindEulerian(){
    for(int i = 0; i<n; ++i){
        out_deg[i]+=G[i].size();
        for(int &j : G[i]) ++in_deg[j];
    }
    if(!Eulerian()) return;
    dfs(stV());
}
