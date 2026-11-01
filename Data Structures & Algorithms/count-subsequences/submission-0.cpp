class Solution {
public:
    int countSubsequence(int i, int j, string s, string t, vector<vector<int> > & dp) {
        if(j < 0) {
            return 1;
        }
        if(i < 0) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 0;
        if(s[i] == t[j]) {
            ans += countSubsequence(i-1, j-1, s, t, dp);
            ans += countSubsequence(i-1, j, s, t, dp);
        } else {
            ans += countSubsequence(i-1, j, s, t, dp);
        }
        dp[i][j] = ans;
        return ans;
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int> > dp(n, vector<int> (m, -1));
        return countSubsequence(n-1, m-1, s, t, dp);
    }
};
