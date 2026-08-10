class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n == 0)
            return 0;
        if(s[0] == '0') {
            return 0;
        } else if(n == 1) {
            return 1;
        }
        vector<int> dp(n,0);
        dp[0] = 1;
        if(s[1] == '0') {
            int fi = s[0] - '0';
            if(fi >= 3) {
                return 0;
            }
            dp[1] = 1;
        } else {
            int fi = s[0] - '0';
            if(fi >= 3 || (fi == 2 && s[1]-'0' > 6)) {
                dp[1] = 1;
            } else {
                dp[1] = 2;
            }
        }
        //cout<<dp[0]<<" "<<dp[1]<<" ";
        for(int i = 2; i < n; i++) {
            int add = 0;
            if(s[i] == '0') {
                int fi = s[i-1] - '0';
                if(fi >= 3 || fi == 0) {
                    return 0;
                } 
                dp[i] = dp[i-2];
            } else {
                int fi = s[i-1] - '0';
                if(fi == 1 || (fi == 2 && s[i] - '0' <= 6)) {
                    add = 1;
                } 
                dp[i] = dp[i-2]*add + dp[i-1];
            }
            //cout<<dp[i]<<" ";
        }
        return dp[n-1];
    }
};
