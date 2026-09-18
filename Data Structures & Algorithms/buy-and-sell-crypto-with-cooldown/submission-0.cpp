class Solution {
public:
    int maxProfitHelper(int i, int j, vector<int> & prices, vector<vector<int> > & dp) {
        int n = prices.size();
        if(i >= n) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(j != n){
            dp[i][j] = max(maxProfitHelper(i+2, n, prices, dp) + prices[i] - prices[j], maxProfitHelper(i+1, j, prices, dp));
        } else {
            dp[i][j] = max(maxProfitHelper(i+1, i, prices, dp), maxProfitHelper(i+1, j, prices, dp));
        }
        //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        return dp[i][j];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int> >  dp(n, vector<int> (n+1, -1));
        maxProfitHelper(0, n, prices, dp);
        int ans = 0;
        for(int i = 0; i <= n; i++) {
            //for(int j = 0; j < 2; j++) {
                ans = max(ans, dp[0][i]);
            //}
        }
        return ans;        
    }
};
