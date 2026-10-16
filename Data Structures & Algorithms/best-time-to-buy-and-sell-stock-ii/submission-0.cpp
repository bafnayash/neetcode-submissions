class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        int mi = prices[0];
        for(int i = 1; i < n; i++) {
            if(mi < prices[i]) {
                ans += (prices[i] - mi);
                mi = prices[i];
            } else {
                mi = min(mi, prices[i]);
            }
        }
        return ans;
    }
};