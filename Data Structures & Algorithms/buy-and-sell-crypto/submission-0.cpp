class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> mx(n+1,0);
        for(int i = n-1; i >= 0; i--) {
            mx[i] = max(mx[i+1], prices[i]);
        }
        int ans = 0, minPrice = 1e9;
        for(int i = 0; i < n; i++) {
            minPrice = min(prices[i], minPrice);
            ans = max(ans, mx[i+1]-minPrice);
        }   
        return ans;
    }
};
