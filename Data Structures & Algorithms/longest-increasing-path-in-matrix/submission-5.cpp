class Solution {
public:
    struct Position {
        int x, y, val;
    };
    struct comp {
        bool operator() (Position& p1, Position& p2) {
            return p1.val > p2.val;
        }
    };
    int dfs(int x, int y, vector<vector<int> >& vis, vector<vector<int> > & matrix, vector<vector<int> > &dp) {
        int n = matrix.size();
        int m = matrix[0].size();
        if(x < 0 || y < 0 || x >= n || y >= m) {
            return 0;
        }
        if(dp[x][y]) {
            return dp[x][y];
        }
        int val = matrix[x][y];
        int ans = 0;
        if(x+1 < n && !vis[x+1][y] && matrix[x+1][y] > val) {
            vis[x+1][y] = 1;
            ans = max(ans, 1 + dfs(x+1, y, vis, matrix, dp));
            vis[x+1][y] = 0;
        }
        if(x-1 >= 0 && !vis[x-1][y] && matrix[x-1][y] > val) {
            vis[x-1][y] = 1;
            ans = max(ans, 1 + dfs(x-1, y, vis, matrix, dp));
            vis[x-1][y] = 0;
        }
        if(y+1 < m && !vis[x][y+1] && matrix[x][y+1] > val) {
            vis[x][y+1] = 1;
            ans = max(ans, 1 + dfs(x, y+1, vis, matrix, dp));
            vis[x][y+1] = 0;
        }
        if(y-1 >= 0 && !vis[x][y-1] && matrix[x][y-1] > val) {
            vis[x][y-1] = 1;
            ans = max(ans, 1 + dfs(x, y-1, vis, matrix, dp));
            vis[x][y-1] = 0;
        }
        dp[x][y] = ans;
        return ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        //vector<vector<int> > vis(n, vector<int> (m, 0));
        //int mi = 1e7;
        int ans = 0;
        vector<vector<int> > dp(n, vector<int> (m, 0));
        priority_queue<Position, vector<Position>, comp> q;
        for(int i = 0; i < n; i++) {
            int mi = INT_MAX;
            Position coordinates;
            for(int j = 0; j < m; j++) {
                if(mi > matrix[i][j]) {
                    mi = matrix[i][j];
                    coordinates.x = i;
                    coordinates.y = j;
                    coordinates.val = matrix[i][j];
                }
            }
            if(mi < INT_MAX) {
                q.push(coordinates);
            }
        }
        for(int i = 0; i < m; i++) {
            int mi = INT_MAX;
            Position coordinates;
            for(int j = 0; j < n; j++) {
                if(mi > matrix[j][i]) {
                    mi = matrix[j][i];
                    coordinates.x = j;
                    coordinates.y = i;
                    coordinates.val = matrix[j][i];
                }
            }
            if(mi < INT_MAX) {
                q.push(coordinates);
            }
        }
        vector<vector<int> > vis(n, vector<int> (m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                dp[i][j] = dfs(i, j, vis, matrix, dp);
                ans = max(ans, dp[i][j]);   
            }        
        }
        return ans+1;
    }
};
