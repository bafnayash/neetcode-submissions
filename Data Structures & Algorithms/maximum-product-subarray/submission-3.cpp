class Solution {
public:
    int maxProductHelper(int i, int prod, map<int, int>& dp, vector<int> &nums) {
        if(i < 0) {
            return 1;
        }
        if(dp[prod] != INT_MIN) {
            return dp[prod];
        }
        int op1 = maxProductHelper(i-1, prod*nums[i], dp, nums);
        int op2 = maxProductHelper(i-1, prod, dp, nums);
        dp[prod] = max(op1, op2);
        return dp[prod];
    }
    int maxProduct(vector<int>& nums) {
        long ans = 0, cur = INT_MIN, prev = INT_MIN, ele = INT_MIN;
        int n = nums.size(), negs = 0;
        for(int i = 0; i < n; i++) {
            ele = max(ele, (long)nums[i]);
            if(nums[i] == 0) {
                ans = max(ans, cur);
                prev = INT_MIN;
                negs = 0;
                cur = INT_MIN;
            } else if(nums[i] < 0){
                if(negs == 0) {
                    ans = max(ans, cur);
                    negs = nums[i];
                    prev = cur;
                    cur = INT_MIN;
                } else {
                    cur = (cur == INT_MIN) ? negs*nums[i] : cur*negs*nums[i];
                    cur = (prev == INT_MIN) ? cur : cur*prev;
                    prev = INT_MIN;
                    negs = 0;
                    ans = max(ans, cur);
                }
            } else {
                cur = (cur == INT_MIN) ? nums[i] : cur*nums[i];
                ans = max(ans, cur);
            }
            //cout<<ans<<" ";
        }
        cur = INT_MIN;
        prev = INT_MIN;
        ele = INT_MIN;
        negs = 0;
        for(int i = n-1; i >= 0; i--) {
            ele = max(ele, (long)nums[i]);
            if(nums[i] == 0) {
                ans = max(ans, cur);
                prev = INT_MIN;
                negs = 0;
                cur = INT_MIN;
            } else if(nums[i] < 0){
                if(negs == 0) {
                    ans = max(ans, cur);
                    negs = nums[i];
                    prev = cur;
                    cur = INT_MIN;
                } else {
                    cur = (cur == INT_MIN) ? negs*nums[i] : cur*negs*nums[i];
                    cur = (prev == INT_MIN) ? cur : cur*prev;
                    prev = INT_MIN;
                    negs = 0;
                    ans = max(ans, cur);
                }
            } else {
                cur = (cur == INT_MIN) ? nums[i] : cur*nums[i];
                ans = max(ans, cur);
            }
            //cout<<ans<<" ";
        }
        if(ans == 0) {
            return ele;
        }
        return ans;
    }
};
