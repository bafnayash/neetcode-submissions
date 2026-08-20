class Solution {
public:
    int longestCommonSubsequenceHelper(int i, int j, string& t1, string& t2, vector<vector<int> > &dp) {
        int n = t1.size();
        int m = t2.size();
        if(i < 0 || j < 0 || i >= n || j >= m) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(t1[i] == t2[j]) {
            dp[i][j] = 1 + longestCommonSubsequenceHelper(i-1, j-1, t1, t2, dp);
        }
        dp[i][j] = max(dp[i][j], longestCommonSubsequenceHelper(i-1, j, t1, t2, dp));
        dp[i][j] = max(dp[i][j], longestCommonSubsequenceHelper(i, j-1, t1, t2, dp));
        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int> > dp(n, vector<int> (m, -1));
        return longestCommonSubsequenceHelper(n-1, m-1, text1, text2, dp);   
    }
};
