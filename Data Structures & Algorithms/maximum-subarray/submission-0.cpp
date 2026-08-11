class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, cur = 0, n = nums.size();
        int ans = -1e6;
        for(int i = 0; i < n; i++) {
            cur += nums[i];
            ans = max(ans, cur);
            cur = max(cur, 0);
        }
        return ans;
    }
};
;