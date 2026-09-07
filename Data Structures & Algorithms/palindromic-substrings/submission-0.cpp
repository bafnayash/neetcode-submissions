class Solution {
public:
    int isPalindrome(int i, int j, string &s, vector<vector<int> > &dp) {
        int n = j-i+1;
        if(i > j || i >= s.size() || j < 0) {
            return 0;
        }
       // cout<<dp[i][j]<<" "<<i<<" "<<j<<endl;
        if(dp[i][j] >= 0) { 
            return dp[i][j];
        }
        if(s[i] != s[j]) {
           dp[i][j] = 0;
        } else if(n == 2 || n == 1) {
            dp[i][j] = 1;
        } else {
            dp[i][j] = isPalindrome(i+1, j-1, s, dp);
        }
        return dp[i][j];
    }
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int> > dp(n, vector<int> (n,-1));
        for(int i = n-1; i >= 0; i--) {
            for(int j = i; j < n; j++) {
                dp[i][j] = isPalindrome(i, j, s, dp);
               // cout<<dp[i][j]<<" "<<i<<" "<<j<<endl;
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ans += (dp[i][j] == 1);
            }
        }
        return ans;
    }
};
