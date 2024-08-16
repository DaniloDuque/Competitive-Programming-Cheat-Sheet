int n;
vector<pair<int, int>> G[MAX];
bitset<MAX> tkn;
priority_queue<pair<int, int>> pq;

void process(int v){
    tkn.set(v);
    for(auto &e : G[v]) if(!tkn.test(e.second)) pq.emplace(-e.first, e.second);
}

int prim(){

    tkn.reset(); process(0);
    int mst = 0;
    while(!pq.empty()){
        int c = pq.top().first, v = pq.top().second; pq.pop();
        if(!tkn.test(v)) mst -= c, process(v);
    }return mst;
    
}
