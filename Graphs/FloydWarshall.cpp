int G[MAX][MAX], n;

void FW(){
    for(int k = 0; k<n; ++k)
        for(int i = 0; i<n; ++i)
            if(G[i][k] < INF)
                for(int j = 0; j<n; ++j)
                    if(G[k][j] < INF) G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
} 
