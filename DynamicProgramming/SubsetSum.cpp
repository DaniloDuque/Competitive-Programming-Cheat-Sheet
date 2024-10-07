int dp[MAX][MAX], n;

void subsetSum() {
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<MAX; ++i) dp[i][0] = 1;
    for(int i=1; i<MAX; ++i) 
        for(int j=1; j<MAX; ++j)
            dp[i][j] = (j<nums[i-1])? dp[i-1][j] : dp[i-1][j] || dp[i-1][j-nums[i-1]];
}
