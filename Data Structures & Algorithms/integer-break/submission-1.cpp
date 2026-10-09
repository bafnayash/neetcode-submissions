class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 1;
        for(int i = 0; i <= n; i++) {
            for(int j = 1; j <= n-1; j++) {
                if(i + j <= n) {
                    dp[i+j] = max(j*dp[i], dp[i+j]);
                    //cout<<i+j<<" "<<dp[i+j]<<endl;
                }
            }
        }
        return dp[n];
    }
};