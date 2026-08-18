class Solution {
public:
    vector<int> ans;
    /*void dfs(int i, int j, vector<vector<int> > & vis, vector<vector<int> > & matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        if(i < 0 || j < 0 || i >= n || j >= m) {
            return;
        }
        if(vis[i][j] == 1) {
            return;
        }
        ans.push_back(matrix[i][j]);
        vis[i][j] = 1;
        dfs(i, j+1, vis, matrix);
        dfs(i+1, j, vis, matrix);
        dfs(i, j-1, vis, matrix);
        dfs(i-1, j, vis, matrix);
    }*/
    void traverseBorders(int i, int l, int r, vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(l > r || i >= (n+1)/2) {
            return;
        }
        /*if(l == r) {
            //cout<<n<<" "<<i<<" "<<l;
            ans.push_back(matrix[i][l]);
            return;
        }*/
        for(int c = l; c <= r; c++) {
            ans.push_back(matrix[i][c]);
        }
        for(int row = i+1; row <= n-1-i; row++) {
            ans.push_back(matrix[row][r]);
        }
        if(i == n-1-i || l == r)
            return;
        for(int c = r-1; c >= l; c--) {
            ans.push_back(matrix[n-1-i][c]);
        }
        for(int row = n-1-i-1; row > i; row--) {
            ans.push_back(matrix[row][l]);
        }
        traverseBorders(i+1, l+1, r-1, matrix);
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        ans.clear();
        int l = 0, r = n-1;
        traverseBorders(0, 0, m-1, matrix);
        return ans;
    }
};
