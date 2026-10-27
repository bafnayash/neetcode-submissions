class Solution {
public:
    bool isInterleaveHelper(int i, int j, int k, int c1, int c2, string cur, string s1, string s2, string s3, vector<vector<vector<int> > > & dp) {
        int n = s1.size();
        int m = s2.size();
        if(i >= n && j >= m && k >= n + m) {
            return abs(c1-c2) <= 1;
        }
        if(k > (n+m)) {
            return false;
        }
        if(i >= n) {
            if(s2[j] == s3[k]) {
                cur.push_back(s2[j]);
                return isInterleaveHelper(i, j+1, k+1, c1, c2+1, cur, s1, s2, s3, dp);
            }
            return false;
        }
        if(j >= m) {
            if(s1[i] == s3[k]) {
                cur.push_back(s1[i]);
                return isInterleaveHelper(i+1, j, k+1, c1+1, c2, cur, s1, s2, s3, dp);
            }
            return false;
        }
        if(dp[i][j][k] != -1) {
            return dp[i][j][k];
        }
        bool ans = false;
        if(s1[i] == s3[k]) {
            cur.push_back(s1[i]);
            //cout<<cur<<endl;
            ans |= isInterleaveHelper(i+1, j, k+1, c1+1, c2, cur, s1, s2, s3, dp);
            cur.pop_back();
        }
        if(s2[j] == s3[k]) {
            cur.push_back(s2[j]);
            //cout<<cur<<endl;
            ans |= isInterleaveHelper(i, j+1, k+1, c1, c2+1, cur, s1, s2, s3, dp);
            cur.pop_back();
        }
        //cout<<cur<<endl;
        dp[i][j][k] = ans;
        return ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int targetSize = s3.size();
        if(n + m != targetSize) {
            return false;
        }
        string match = "";
        vector<vector<vector<int> > > dp(n+1, vector<vector<int> > (m+1, vector<int> (n+m+1, -1)));
        return isInterleaveHelper(0, 0, 0, 0, 0, match, s1, s2, s3, dp);
    }
};
