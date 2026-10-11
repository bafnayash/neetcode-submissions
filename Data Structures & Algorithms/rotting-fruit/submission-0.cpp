class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        vector<vector<int> > grid(g);
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int> > q;
        vector<vector<int> > vis(n, vector<int> (m, -1));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    //cout<<i<<" "<<j;
                    q.push({i,j});
                    vis[i][j] = 1;
                    grid[i][j] = 0;
                    //dfs(i, j, 0, grid, vis);
                }
                if(grid[i][j] == 1) {
                    grid[i][j] = INT_MAX;
                }
            }
        }
        int level = 0;
        while(!q.empty()) {
          //  cout<<q.size();
            int size = q.size();
            //cout<<level<<" LEVEL ";
            for(int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                //cout<<x<<" "<<y<<endl;
                q.pop();
                if(x+1 < n && vis[x+1][y] == -1 && grid[x+1][y] > 2) {
                    q.push({x+1, y});
                    vis[x+1][y] = 1;
                }
                if(x-1 >= 0 && vis[x-1][y] == -1 && grid[x-1][y] > 2) {
                    q.push({x-1, y});
                    vis[x-1][y] = 1;
                }
                if(y+1 < m && vis[x][y+1] == -1 && grid[x][y+1] > 2) {
                    q.push({x, y+1});
                    vis[x][y+1] = 1;
                }
                if(y-1 >= 0 && vis[x][y-1] == -1 && grid[x][y-1] > 2) {
                    q.push({x, y-1});
                    vis[x][y-1] = 1;
                }
                if(grid[x][y] > 0) {
                    grid[x][y] = min(level, grid[x][y]);
                }
                //vis[x][y] = 1;
            }
            level++;
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == INT_MAX) {
                    return -1;
                }
                ans = max(ans, grid[i][j]);
            }
        }
        return ans;
    }
};
