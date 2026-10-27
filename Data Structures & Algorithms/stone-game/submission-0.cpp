class Solution {
public:
    int stoneGameHelper(int i, int j, bool aliceTurn, vector<int> & piles, vector<vector<vector<int>> > & dp) {
        int n = piles.size();
        if(i > j || j < 0 || i >= n) {
            return 0;
        }
        if(dp[i][j][aliceTurn] > -1e8) {
            return dp[i][j][aliceTurn];
        }
        int ansAlice = 0, ansBob = 1e7;
        if(aliceTurn) {
            ansAlice = max(piles[i] + stoneGameHelper(i+1, j, !aliceTurn, piles, dp), ansAlice);
            ansAlice = max(piles[j] + stoneGameHelper(i, j-1, !aliceTurn, piles, dp), ansAlice);
            dp[i][j][aliceTurn] = ansAlice;
        } else {
            ansBob = min(-piles[i] + stoneGameHelper(i+1, j, !aliceTurn, piles, dp), ansBob);
            ansBob = min(-piles[j] + stoneGameHelper(i, j-1, !aliceTurn, piles, dp), ansBob);
            dp[i][j][aliceTurn] = ansBob;
        }
        return dp[i][j][aliceTurn];
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int> > > dp(n, vector<vector<int> > (n, vector<int> (2, -1e8)));
        return stoneGameHelper(0, n-1, true, piles, dp);
    }
};