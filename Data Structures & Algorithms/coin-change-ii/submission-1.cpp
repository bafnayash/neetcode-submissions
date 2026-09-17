class Solution {
public:
    int helper(int i, int amount, vector<int> & coins, vector<vector<int > > & dp) {
        if(i < 0 || amount < 0) {
            return 0;
        }
        //cout<<i<<" "<<amount<<endl;
        if(amount == 0) {
            return 1;
        }
        if(dp[i][amount]) {
            return dp[i][amount];
        }
        dp[i][amount] = helper(i, amount - coins[i], coins, dp) + helper(i-1, amount, coins, dp);
        return dp[i][amount];
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        if(amount == 0)
            return 1;
        vector<vector<int > > dp(n, vector<int> (amount+1, 0));
        helper(n-1, amount, coins, dp);
        int ans = dp[n-1][amount];
        return ans;
    }
};
 