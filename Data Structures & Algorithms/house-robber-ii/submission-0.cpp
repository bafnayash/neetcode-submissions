class Solution {
public:
   int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        if(n == 1) {
            return nums[0];
        }
        if(n == 2) {
            return max(nums[0], nums[1]);
        }
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }
        vector<vector<int> > dp(n, vector<int> (2, 0));
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        for(int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = dp[i-1][0] + nums[i]; 
        }
        //int sub1 = (nums[1] >= nums[0] && nums[1] >= nums[0] + nums[2]) ? 0 : nums[0];
        int ans = max(dp[n-2][0], dp[n-2][1]);
        vector<vector<int> > dp2(n, vector<int> (2, 0));
        dp2[1][0] = 0;
        dp2[1][1] = nums[1];
        for(int i = 2; i < n; i++) {
            dp2[i][0] = max(dp2[i-1][0], dp2[i-1][1]);
            dp2[i][1] = dp2[i-1][0] + nums[i]; 
        }
        ans = max(ans, max(dp2[n-1][0], dp2[n-1][1]));
        return ans;
    }
};
