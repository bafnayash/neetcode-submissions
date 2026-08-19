class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        set<pair<int, int> > s;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                //cout<<c.contains(j)<<" ";
                if(matrix[i][j] == 0 && !s.contains({i,j})) {
                    //cout<<i<<" "<<j<<endl;
                    for(int k = 0; k < n; k++) {
                        if(matrix[k][j]) {
                            //cout<<k<<" "<<j<<endl;
                            s.insert({k,j});
                        }
                        matrix[k][j] = 0;
                    }
                    for(int k = 0; k < m; k++) {
                        if(matrix[i][k]) {
                            //cout<<i<<" "<<k<<endl;
                            s.insert({i,k});
                        }
                        matrix[i][k] = 0;
                    }
                    //r.insert(i);
                    //c.insert(j);
                    //break;
                }
            }
        }
    }
};
