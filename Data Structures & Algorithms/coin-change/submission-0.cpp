class Solution {
public:
    int coinChangeHelper(int i, int amount, vector<vector<int> > &dp, vector<int> & coins) {
        int n = coins.size();
        if(i < 0 && amount != 0) {
            return 1e6;
        } else if(amount < 0) {
            return 1e6;
        } else if(i < 0) {
            return 0;
        }
        if(dp[i][amount] != -1) {
            return dp[i][amount];
        }
        int op1 = coinChangeHelper(i-1, amount, dp, coins);
        int op2 = 1 + coinChangeHelper(i, amount-coins[i], dp, coins);
        dp[i][amount] = min(op1, op2);
        //cout<<i<<" "<<amount<<" "<<dp[i][amount]<<endl;
        return dp[i][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;
        int n = coins.size();
        vector<vector<int> > dp(n, vector<int> (amount+1, -1));
        coinChangeHelper(n-1, amount, dp, coins);
        if(dp[n-1][amount] == 1e6) {
            return -1;
        }
        return dp[n-1][amount];
    }
};
