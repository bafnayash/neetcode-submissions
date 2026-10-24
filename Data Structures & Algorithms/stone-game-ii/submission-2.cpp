class Solution {
public:
    int dfs(int i, int m, bool alice, vector<int> & piles, vector<vector<vector<int> > >& dp) {
        int n = piles.size();
        if(i >= n-1) {
            return 0;
        }
        if(dp[i+1][m][alice] != -1) {
            return dp[i+1][m][alice];
        }
        int cur = 0;
        int stoneSum = 0;
        if(!alice) {
            cur = 1e8;
            for(int j = i+1; j <= min(i+2*m, n-1); j++) {
                stoneSum += piles[j];
                int tempM = max(m, j-i);
                cur = min(cur, dfs(j, min(tempM, n), !alice, piles, dp));
               // cout<<i<<" "<<alice<<" "<<stoneSum<<" "<<cur<<endl;
            }
        } else {
            for(int j = i+1; j <= min(i+2*m, n-1); j++) {
                stoneSum += piles[j];
                int tempM = max(m, j-i);
                cur = max(cur, stoneSum + dfs(j, min(tempM, n), !alice, piles, dp));
                //cout<<i<<" "<<alice<<" "<<stoneSum<<" "<<cur<<endl;
            }
        }
        //if(i >= 0)
        dp[i+1][m][alice] = cur;
        return cur;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        //vector<int> pre(n+1, 0);
        vector<vector<vector<int> > > dp(n+1, vector<vector<int> > (2*n, vector<int> (2,-1)));
        return dfs(-1, 1, true, piles, dp);
        /*for(int i = 0; i < n; i++) {
            pre[i+1] = pre[i] + piles[i];
        }
        int alice = 0;
        int i = 1, m = 1;
        while(i <= n) {
            alice += pre[min(2*m+i-1, n)] - pre[i-1];
            i += 2*m;
            m *= 2;
            i += 2*m;
        }
        return alice;*/
    }
};