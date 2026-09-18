class Solution {
public:
    int tot;
    int helper(int i, int sum, int target, vector<int> & nums, vector<vector<int> > & dp) {
        if(i == -1 && sum == target) {
            return 1;
        }
        if(i < 0) {
            return 0;
        }
        if(dp[i][sum+tot] != -1) {
            return dp[i][sum+tot];
        }
        dp[i][sum+tot] = helper(i-1, sum + nums[i], target, nums, dp) + helper(i-1, sum - nums[i], target, nums, dp);
        //cout<<i<<" "<<sum+tot<<" "<<dp[i][sum+tot]<<endl;
        return dp[i][sum+tot];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        tot = 0;
        for(int i = 0; i < n; i++) {
            tot += nums[i];
        }
        vector<vector<int> > dp(n, vector<int> (2*tot+1, -1));
        //dp[0] = 1;
        return helper(n-1, 0, target, nums, dp); 
        //for(int i = 0; i < )
        //return dp[n-1][target+tot];
    }
};
