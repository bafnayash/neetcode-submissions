class Solution {
public:
    int dfs(int i, int j, vector<int>& nums, vector<vector<int> > &dp) {
        int n = nums.size();
        if(i >= n) {
            return 0;
        }
        if(dp[i][j+1] != -1) {
            return dp[i][j+1];
        }
        dp[i][j+1] = dfs(i+1, j, nums, dp);
        if(j == -1 || nums[i] > nums[j]) {
            dp[i][j+1] = max(1+dfs(i+1, i, nums, dp), dp[i][j+1]);
        } 
        return dp[i][j+1];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int> > dp(n, vector<int>(n+1, -1));
        //for(int i = 0; i < n; i++) {
        //    dp[i][i] = 1;
        //}
        dfs(0, -1, nums, dp);
        int ans = -1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= n; j++) {
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
        /*map<int, int> dp;
        for(int i = 0; i < n; i++) {
            auto cur = dp.find(nums[i]);
            if(cur == dp.end()) {
                dp[nums[i]] = 1;
                auto curNew = dp.find(nums[i]);
                if(curNew != dp.begin()) {
                    dp[nums[i]] = 1 + prev(curNew)->second;
                }
            } else if(cur == dp.begin()) {
                dp[nums[i]] = 1;
            } else {
                dp[nums[i]] = 1 + prev(cur)->second;
            } 
            cout<<nums[i]<<" "<<dp[nums[i]]<<endl;
        }
        int ans = 0;
        for(auto it:dp) {
            ans = max(ans, it.second);
        }
        return ans;*/
    }
};
