vector<int> G[MAX];

void BFS(int st){

    bitset<MAX> v; queue<int> bfs;
    bfs.push(st); v.set(st);
    while(!bfs.empty()){
        st = bfs.front(), bfs.pop();
        for(int &nx : G[st])
            if(!v.test(nx)) bfs.push(nx), v.set(nx);
    }
}
