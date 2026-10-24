class Solution {
public:
    int dfs(int i, bool aliceTurn, vector<int> & stoneValue, vector<vector<int> > & dp) {
        int n = stoneValue.size();
        if(i >= n) {
            return 0;
        }
        if(dp[i][aliceTurn] > -1e9) {
            return dp[i][aliceTurn];
        }
        if(aliceTurn) {
            int cur = -1e6;
            int score1 = stoneValue[i];
            int score2 = (i + 1 < n) ? stoneValue[i+1] : 0;
            int score3 = (i + 2 < n) ? stoneValue[i+2] : 0;
            cur = max(cur, score1 + dfs(i+1, false, stoneValue, dp));
            cur = max(cur, score1 + score2 + dfs(i+2, false, stoneValue, dp));
            cur = max(cur, score1 + score2 + score3 + dfs(i+3, false, stoneValue, dp));
            dp[i][aliceTurn] = cur;
            return cur;
        } else {
            int cur = 1e6;
            int score1 = stoneValue[i];
            int score2 = (i + 1 < n) ? stoneValue[i+1] : 0;
            int score3 = (i + 2 < n) ? stoneValue[i+2] : 0;
            cur = min(cur, -score1 + dfs(i+1, true, stoneValue, dp));
            cur = min(cur, -score1 - score2 + dfs(i+2, true, stoneValue, dp));
            cur = min(cur, -score1 - score2 - score3 + dfs(i+3, true, stoneValue, dp));
            dp[i][aliceTurn] = cur;
            return cur;
        }
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int i = 0, sumA = 0, sumB = 0;
        bool turnA = true;
        vector<vector<int> >  dp(n, vector<int> (2, -1e9));
        int ans = dfs(0, true, stoneValue, dp);
        if(ans > 0) {
            return "Alice";
        } else if(ans < 0) {
            return "Bob";
        } else {
            return "Tie";
        }
        /*while(i < n) {
            if(turnA) {
                sumA += stoneValue[i];
                int temp = 0, temp2 = 0;
                if(i+1 < n) {
                    temp += stoneValue[i+1];
                }
                if(i+2 < n) {
                    temp2 = temp + stoneValue[i+2];
                }
                if(temp2 > 0) {
                    i += 3;
                    sumA += temp2;
                } else if(temp > 0) {
                    i += 2;
                    sumA += temp;
                } else {
                    i++;
                }
                turnA = false;
            } else {
                sumB += stoneValue[i];
                int temp = 0, temp2 = 0;
                if(i+1 < n) {
                    temp += stoneValue[i+1];
                }
                if(i+2 < n) {
                    temp2 = temp + stoneValue[i+2];
                }
                if(temp2 > 0) {
                    i += 3;
                    sumB += temp2;
                } else if(temp > 0) {
                    i += 2;
                    sumB += temp;
                } else {
                    i++;
                }
                turnA = true;
            }
        }
        if(sumA > sumB) {
            return "Alice";
        } else if(sumB > sumA) {
            return "Bob";
        } else {
            return "Tie";
        }*/
    }
};