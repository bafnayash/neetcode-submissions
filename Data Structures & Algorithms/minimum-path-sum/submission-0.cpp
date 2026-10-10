class Solution {
public:
    int dfs(int i, int j, vector<vector<int> > &grid, vector<vector<int> > &dp) {
        if(i < 0 || j < 0) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        dp[i][j] = grid[i][j] + min(dfs(i-1, j, grid, dp), dfs(i, j-1, grid, dp));
        return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int> > dp(n, vector<int> (m, 1e6));
        //dfs(n-1, m-1, grid, dp);
        dp[0][0] = grid[0][0];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i-1 >= 0) {
                    dp[i][j] = min(dp[i-1][j] + grid[i][j], dp[i][j]);
                }
                if(j-1 >= 0) {
                    dp[i][j] = min(dp[i][j-1] + grid[i][j], dp[i][j]);
                }
            }
            //cout<<endl;
        }
        return dp[n-1][m-1];
    }
};