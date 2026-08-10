class Solution {
public:
    set<vector<int> > ans;
    void combinationSumHelper(int i, vector<int>& nums, int t, vector<int> cur) {
        int n = nums.size();
        if(t == 0) {
            ans.insert(cur);
            return;
        } else if(i >= n || t < 0) {
            return;
        }
        combinationSumHelper(i+1, nums, t, cur);
        cur.push_back(nums[i]);
        combinationSumHelper(i, nums, t-nums[i], cur);
        combinationSumHelper(i+1, nums, t-nums[i], cur);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        combinationSumHelper(0, nums, target, cur);
        vector<vector<int> > ret;
        for(auto it:ans) {
            ret.push_back(it);
        }
        return ret;
    }
};
