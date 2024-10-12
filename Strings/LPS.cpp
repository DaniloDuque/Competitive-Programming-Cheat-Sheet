int n, dp[MAX][MAX];

string LPS(string &s) {
    int st=0, mLen=1;
    for(int i=0; i<n; ++i) dp[i][i]=1;
    for(int i=0; i<n-1; ++i) if(s[i]==s[i+1]) dp[i][i+1]=1, st=i, mLen=2;
    for(int len=3; len<=n; ++len)
        for(int i=0; i<=n-len; ++i) {
            int j=i+len-1;
            if(s[i]==s[j] && dp[i+1][j-1]) dp[i][j]=1, st=i, mLen=len;
        }
    return s.substr(st, mLen);
}
