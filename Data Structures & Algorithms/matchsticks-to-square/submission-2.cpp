class Solution {
public:
    map<vector<int>, int> dp;
    int maxTarget;
    bool makesquareHelper(int i, int a, int b, int c, int d, vector<int> & matchsticks) {
        if(i < 0 && a == b && b == c && c == d) {
            return true;
        } else if(i < 0) {
            return false;
        }
        if(max(max(a, b), max(c, d)) > maxTarget) {
            return false;
        }
        if(dp.contains({i, a, b, c, d})) {
            return dp[{i, a, b, c, d}];
        }
        bool op1 = makesquareHelper(i-1, a+matchsticks[i], b, c, d, matchsticks);
        bool op2 = makesquareHelper(i-1, a, b+matchsticks[i], c, d, matchsticks);
        bool op3 = makesquareHelper(i-1, a, b, c+matchsticks[i], d, matchsticks);
        bool op4 = makesquareHelper(i-1, a, b, c, d+matchsticks[i], matchsticks);
        dp[{i, a, b, c, d}] = op1 || op2 || op3 || op4;
        return op1 || op2 || op3 || op4;
    }
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += matchsticks[i];
        }
        if(sum%4 != 0) {
            return false;
        }
        maxTarget = sum/4;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        return makesquareHelper(n-1, 0, 0, 0, 0, matchsticks);
    }
};