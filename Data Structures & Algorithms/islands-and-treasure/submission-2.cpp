class Solution {
public:
    /*void dfs(int i, int j, int cur, vector<vector<int> > & grid, vector<vector<int> > &vis) {
        int n = grid.size();
        if(n == 0)
            return;
        int m = grid[0].size();
        if(i < 0 || j < 0 || i >= n || j >= m) {
            return;
        }
        if(grid[i][j] == -1) {
            return;
        }
        if(vis[i][j] != -1) {
            return;
        }
        vis[i][j] = 1;
        if(grid[i][j] != 0)
            grid[i][j] = min(grid[i][j], cur);
        dfs(i, j-1, cur+1, grid, vis);
        dfs(i, j+1, cur+1, grid, vis);
        dfs(i-1, j, cur+1, grid, vis);
        dfs(i+1, j, cur+1, grid, vis);
        //return grid[i][j];
    }*/
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int> > q;
        vector<vector<int> > vis(n, vector<int> (m, -1));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    //cout<<i<<" "<<j;
                    q.push({i,j});
                    vis[i][j] = 1;
                    //dfs(i, j, 0, grid, vis);
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
                if(x+1 < n && vis[x+1][y] == -1 && grid[x+1][y] > 0) {
                    q.push({x+1, y});
                    vis[x+1][y] = 1;
                }
                if(x-1 >= 0 && vis[x-1][y] == -1 && grid[x-1][y] > 0) {
                    q.push({x-1, y});
                    vis[x-1][y] = 1;
                }
                if(y+1 < m && vis[x][y+1] == -1 && grid[x][y+1] > 0) {
                    q.push({x, y+1});
                    vis[x][y+1] = 1;
                }
                if(y-1 >= 0 && vis[x][y-1] == -1 && grid[x][y-1] > 0) {
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
    }
};
