vector<int> G[MAX], topSort;
int in_deg[MAX], n;

bool Khan(){
    queue<int> Q;
    for(int i = 0; i<n; ++i) for(int &j : G[i]) ++in_deg[j];
    for(int i = 0; i<n; ++i) if(!in_deg[i]) Q.push(i);
    while(!Q.empty()){
        int c = Q.front(); Q.pop();
        topSort.push_back(c);
        for(int &j : G[c]) if(!(--in_deg[j])) Q.push(j);
    }return topSort.size() == n;
}


