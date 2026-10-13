class Solution {
public:
    /*pair<int, int> getParent(pair<int,int> p1, map<pair<int, int>, pair<int,int> >& par) {
        if(par[p1] != p1) {
            p1 = par[p1];
        }
        return p1;
    }
    void merge(pair<int, int> p1, pair<int,int> p2, map<pair<int, int>, pair<int,int> >& par, map<pair<int,int>, int>& size) {
        auto par1 = getParent(p1, par);
        auto par2 = getParent(p2, par);
        if(p1 == p2) {
            return;
        }
        if(size[par1] >= size[par2]) {
            par[par2] = par1;
            size[par1] += size[par2];
        } else {
            par[par1] = par2;
            size[par2] += size[par1];
        }
    }*/
    bool dfs(int i, int j, bool & update, vector<vector<char> > &board, set<pair<int,int> > & vis) {
        int n = board.size();
        int m = board[0].size();
        if(i < 0 || j < 0 || i >= n || j >= m) {
            update = false;
            return false;
        }
        if(board[i][j] == 'X' || vis.contains({i,j})) {
            return true;
        }
        vis.insert({i,j});
        bool up = dfs(i-1, j, update, board, vis);
        bool down = dfs(i+1, j, update, board, vis);
        bool right = dfs(i, j+1, update, board, vis);
        bool left = dfs(i, j-1, update, board, vis);
        return up && down && left && right && update;
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        /*map<pair<int, int>, pair<int,int> > par;
        map<pair<int,int>, int> size;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                par[{i,j}] = {i,j};
                size[{i,j}] = 1;
            }
        }*/
        //vector<vector<int> > vis(n+1, vector<int> (m+1, -1));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'O') {
                    bool update = true;
                    //cout<<i<<" "<<j<<endl;
                    set<pair<int,int> > vis;
                    bool ans = dfs(i, j, update, board, vis);
                    if(ans) {
                        for(auto it:vis) {
                            board[it.first][it.second] = 'X';
                        }
                    }
                }
            }
        }
    }
};
