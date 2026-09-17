class Solution {
public:
    pair<int,int> getParent(int i, int j, map<pair<int,int>, pair<int,int> > & par) {
        pair<int,int> p1 = {i,j};
        //int cnt = 0;
        while(par[{p1.first, p1.second}].first != p1.first || par[{p1.first, p1.second}].second != p1.second) {
            //cout<<i<<" "<<j<<endl;
            p1 = par[{i,j}];
        }
        //cout<<"END\n";
        return p1;
    }
    bool merge(int i, int j, int x, int y, map<pair<int,int>, pair<int,int> > & par, vector<vector<int> > & size) {
        auto par1 = getParent(i, j, par);
        auto par2 = getParent(x, y, par);
        if(par1 == par2) {
            return false;
        }
        if(size[par1.first][par1.second] >= size[par2.first][par2.second]) {
            par[par2] = par1;
            size[par1.first][par1.second] += size[par2.first][par2.second];
        } else {
            par[par1] = par2;
            size[par2.first][par2.second] += size[par1.first][par1.second];
        }
        return true;
    }
    void dfs(int i, int j, vector<vector<int> > &grid, map<pair<int,int>, pair<int,int> > & par, vector<vector<int> > & size, vector<vector<int>> & vis) {
        int n = grid.size();
        int m = grid[0].size();
        if(i < 0 || j < 0 || i >= n || j >= m || vis[i][j] != -1) {
            return; 
        }
        //cout<<i<<" "<<j<<endl;
        vis[i][j] = 1;
        if(i+1 < n && grid[i+1][j]) {
            if(merge(i, j, (i+1)%n, j, par, size))
                dfs((i+1)%n, j, grid, par, size, vis);
        }
        if(i-1 >= 0 && grid[i-1][j]) {
            if(merge(i, j, i-1, j, par, size))
                dfs(i-1, j, grid, par, size, vis);
        }
        if(i < n && j+1 < m && grid[i][j+1]) {
            if(merge(i, j, i, j+1, par, size))
                dfs(i, j+1, grid, par, size, vis);
        }
        if(i < n && j-1 >= 0 && grid[i][j-1]) {
            if(merge(i, j, i, j-1, par, size))
                dfs(i, j-1, grid, par, size, vis);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        map<pair<int,int>, pair<int,int> > par;
        vector<vector<int> > size(n, vector<int> (m,0));
        vector<vector<int> > vis(n, vector<int> (m, -1));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j]) {
                    par[{i,j}] = {i,j};
                    size[i][j] = 1;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] && vis[i][j] == -1) {
                    dfs(i, j, grid, par, size, vis);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans = max(ans, size[i][j]);
            }
        }
        return ans;
    }
};
