class Solution {
public:
    vector<int> getParent(int i, int j, vector<vector<vector<int> >> &par) {
        vector<int> cur = par[i][j];
        while(par[cur[0]][cur[1]] != cur) {
            cur = par[cur[0]][cur[1]];
        }
        return cur;
    }
    void joinSets(int i, int j, int y, int z, vector<vector<char> > &grid, vector<vector<vector<int> >> &par, vector<vector<int> > & size) {
        vector<int> par1 = getParent(i, j, par);
        vector<int> par2 = getParent(y, z, par);
        //cout<<"Union: "<<i<<" "<<j<<" "<<y<<" "<<z<<endl;
        if(size[par1[0]][par1[1]] >= size[par2[0]][par2[1]]) {
            par[y][z] = par1;
            size[par1[0]][par1[1]] += size[par2[0]][par2[1]];
        } else {
            par[i][j] = par2;
            size[par2[0]][par2[1]] += size[par1[0]][par1[1]];
        }
    }
    /*void dfs(int i, int j, int prev1, int prev2, vector<vector<vector<int> >> &par, vector<vector<char> > &grid) {
        int n = grid.size();
        int m = grid[0].size();
        string temp = to_string(i) + "_" + to_string(j);
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '#') {
            return;
        }
        //vis.insert(temp);
        if(grid[i][j] == '1') {
            grid[i][j] = '#';
            if(prev1 != -1 && prev2 != -1) { 
                joinSets(prev1, prev2, i, j, grid, par);
            }
            dfs(i+1, j, i, j, par, grid);
            dfs(i, j+1, i, j, par, grid);
            dfs(i-1, j, i, j, par, grid);
            dfs(i, j-1, i, j, par, grid);
            grid[i][j] = '1';
        }
    }*/
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if(n==0)
            return 0;
        int m = grid[0].size();
        vector<vector<vector<int> >> par(n+1, vector<vector<int> > (m+1,vector<int> (2, -1)));
        stack<vector<int> > q;
        vector<vector<int> > size(n, vector<int> (m,0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1') {
                    par[i][j] = {i,j};
                    size[i][j] = 1;
                    q.push({i,j});
                }
            }
        }
        /*for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                vector<int> curPar = {i, j};
                if(par[i][j] == curPar)
                    dfs(i, j, -1, -1, par, grid);
            }
        }*/
        while(!q.empty()) {
            vector<int> cur = q.top();
            q.pop();
            int x = cur[0], y = cur[1];
            vector<int> curPar = par[x][y];
            vector<int> nextPar = par[x+1][y];
            if(x+1 < n && grid[x+1][y] == '1' && curPar != nextPar) {
                joinSets(x, y, x+1, y, grid, par, size);
                q.push({x+1,y});
            }
            nextPar = par[x][y+1];
            if(y+1 < m && grid[x][y+1] == '1' && curPar != nextPar) {
                joinSets(x, y, x, y+1, grid, par, size);
                q.push({x,y+1});
            }
            if(x >= 1 && grid[x-1][y] == '1' ) {
                nextPar = par[x-1][y];
                if(curPar != nextPar) {
                    joinSets(x, y, x-1, y, grid, par, size);
                    q.push({x-1,y});
                }
            }
            if(y >= 1 && grid[x][y-1] == '1') {
                nextPar = par[x][y-1];
                if(curPar != nextPar) {
                    joinSets(x, y, x, y-1, grid, par, size);
                    q.push({x,y-1});
                }
            }
        }
        int count = 0;
        set<string> ans;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout<<par[i][j][0]<<" "<<par[i][j][1]<<endl;
                string temp = to_string(par[i][j][0])+"_"+to_string(par[i][j][1]);
                if(temp != "-1_-1") {
                    ans.insert(temp);
                }
            }
            //cout<<endl;
        }
        return ans.size();
    }
};
