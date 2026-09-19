class Solution {
public:
    int minDistanceHelper(int i, int j, string word1, string word2, vector<vector<int> > & dp) {
        if(i < 0 && j < 0) {
            return 0;
        } else if(i < 0) {
            return j+1;
        } else if(j < 0) {
            return i+1;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(word1[i] == word2[j]) {
            dp[i][j] = minDistanceHelper(i-1, j-1, word1, word2, dp);
        } else {
            int del = 1 + minDistanceHelper(i-1, j, word1, word2, dp);
            int replace = 1 + minDistanceHelper(i-1, j-1, word1, word2, dp);
            int insert = 1 + minDistanceHelper(i, j-1, word1, word2, dp);
            dp[i][j] = min(del, min(replace, insert));
        }
        //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int> > dp(n+1, vector<int> (m+1, -1));
        if(n == 0) {
            return m;
        }
        if(m == 0) {
            return n;
        }
        return minDistanceHelper(n-1, m-1, word1, word2, dp);
    }
};
