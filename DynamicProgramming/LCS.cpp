int dp[MAX][MAX];

string LCS(string &a, string &b){
  
    for(int i = a.size()-1; i>=0; --i)
        for(int j = b.size()-1; j>=0; --j)
            dp[i][j] = (a[i] == b[j])? 1 + dp[i+1][j+1] : max(dp[i+1][j], dp[i][j+1]);

    string rslt = "";
    for(int i = 0, j = 0; i < a.size() && j < b.size();)
        (a[i] == b[j])? rslt += a[i++], ++j : (dp[i+1][j] > dp[i][j+1])?  ++i : ++j;
    return rslt;

}
