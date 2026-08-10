class Solution {
public:
    vector<vector<int> > ans;
    void combinationSumHelper(int i, vector<int>& nums, int t, vector<int> cur) {
        int n = nums.size();
        if(t == 0) {
            ans.push_back(cur);
            return;
        } else if(i >= n || t < 0 || nums[i] > t) {
            return;
        }
        combinationSumHelper(i+1, nums, t, cur);
        cur.push_back(nums[i]);
        combinationSumHelper(i, nums, t-nums[i], cur);
        //dp[i][t] = 1;
        //combinationSumHelper(i+1, nums, t-nums[i], cur, dp);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int> > dp(n+1, vector<int> (target+1, -1));
        combinationSumHelper(0, nums, target, cur);
        return ans;
    }
};
