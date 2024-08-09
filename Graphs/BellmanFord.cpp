int n, dp[MAX];
vector<pair<int, int>> G[MAX];

void BF(int st){
    
    memset(dp, INF, sizeof(dp)); dp[st] = 0;
    for(int k = 0; k<n; ++k)
        for(int i = 0; i<n; ++i)
            if(dp[i] != INF)
                for(auto &t : G[i])
                    dp[t.first] = min(dp[t.first], dp[i] + t.second);

    for(int i = 0; i<n; ++i)
        if(dp[i] != INF)
            for(auto &p : G[i])
                if(dp[p.first] > dp[i] + p.second) //negative cycle exists

}

