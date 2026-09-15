class Solution {
public:
    bool ans = false;
    int total = 0;
    void dfs(int i, int cur, vector<vector<int> > & dp, vector<int> & nums) {
        if(i < 0) {
            return;
        }
        if(dp[i][cur] != -1 || ans) {
            return;
        }
        if(total - cur == cur) {
            ans = true; 
            return;
        }
        dp[i][cur] = 0;
        dfs(i-1, cur+nums[i], dp, nums);
        dfs(i-1, cur, dp, nums);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            total += nums[i];
        }
        vector<vector<int> > dp (n+1, vector<int>(total+1, -1));
        dfs(n-1, 0, dp, nums);
        return ans;
    }
};
