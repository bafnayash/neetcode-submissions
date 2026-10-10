class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        sort(stones.begin(), stones.end());
        vector<vector<int> > dp(n+1, vector<int> (n+1, 1e6));
        for(int i = 0; i < n; i++) {
            dp[i][i] = stones[i];
        }
        for(int i = n-1; i >= 0; i--) {
            for(int j = i+1; j < n; j++) {
                for(int k = i; k+1 <= j; k++) {
                    int op1 = abs(dp[i][k] - dp[k+1][j]);
                    //int op2 = (i+1 < n) ? abs(dp[i+1][j] - stones[i]) : 1e6;
                    int op3 = (i+1 <= j-1 && i+1 < n) ? abs(abs(stones[i] - stones[j])-dp[i+1][j-1]) : 1e6;
                    dp[i][j] = min(min(op1,op3), dp[i][j]);
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[0][n-1];
    }
};