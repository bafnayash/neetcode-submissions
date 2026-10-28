class Solution {
public:
    bool isMatchHelper(int i, int j, char prev, string s, string p, vector<vector<int> > &dp) {
        int n = s.size();
        int m = p.size();
        if(i >= n && j >= m) {
            return true;
        }
        if(j >= m) {
            return false;
        }
        bool ans = false;
        if(i >= n) {
            if(j+1 < m && p[j+1] == '*') {
                ans |= isMatchHelper(i, j+1, p[j], s, p, dp);
            }
            if(j == m-1 && p[j] == '*') {
                ans = true;
            }
            return ans;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(j+1 < m && p[j+1] == '*') {
            ans |= isMatchHelper(i, j+1, p[j], s, p, dp);
        } else if(p[j] == '.') {
            //cout<<"1\n";
            ans |= isMatchHelper(i+1, j+1, '.', s, p, dp);
        } else if(p[j] == '*') {
            //cout<<"2\n";
            if(s[i] == prev || prev == '.') {
                ans |= isMatchHelper(i+1, j+1, prev, s, p, dp);
                ans |= isMatchHelper(i+1, j, prev, s, p, dp);
            }
            // zero matching chars
            ans |= isMatchHelper(i, j+1, '.', s, p, dp);
        } else if(s[i] == p[j]) {
            //cout<<"3\n";
            ans |= isMatchHelper(i+1, j+1, s[i], s, p, dp);
        } 
        dp[i][j] = ans;
        return ans;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int> > dp(n, vector<int> (m, -1));
        return isMatchHelper(0, 0, '.', s, p, dp);
    }
};
