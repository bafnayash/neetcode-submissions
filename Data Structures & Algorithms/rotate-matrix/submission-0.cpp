class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int r = 0; r < n; r++) {
            for(int c = r; c < n; c++) {
                int temp = matrix[r][c];
                matrix[r][c] = matrix[c][r];
                matrix[c][r] = temp;
            }
        }
        /*for(int r = 0; r < n; r++) {
            for(int c = 0; c < n; c++) {
                cout<<matrix[r][c]<<" ";
            }
            cout<<endl;
        }*/
        for(int c = 0; c < n/2; c++) {
            for(int r = 0; r < n; r++) {
                int temp = matrix[r][c];
                matrix[r][c] = matrix[r][n-1-c];
                matrix[r][n-1-c] = temp;
            }
        }
    }
};
