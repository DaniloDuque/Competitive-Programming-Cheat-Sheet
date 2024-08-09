vector<pair<int, int>> G[MAX];
int dp[MAX];

void Dijkstra(int st){
    
    memset(dp, -1, sizeof(dp));
    priority_queue<pair<int, int>> pq;
    dp[st] = 0; pq.push({0, st});
    while(!pq.empty()){
        st = pq.top().second; int w = -pq.top().first; pq.pop(); 
        if(dp[st] != w) continue;
        for(auto &p : G[st]){
            int nxt = p.first; int w = p.second;
            if(dp[nxt] < 0 || dp[st] + w < dp[nxt])
                dp[nxt] = dp[st]+w, pq.emplace(-dp[nxt], nxt);
        }

    }

}

