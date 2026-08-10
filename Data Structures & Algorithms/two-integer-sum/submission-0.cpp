class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, pair<int, int>> traversed;
        int n = nums.size();
        for(int i = n-1;i>=0;i--) {
            if(traversed.contains(target-nums[i])) {
                return {i, traversed[target-nums[i]].second};
            }
            traversed[nums[i]]={1,i};
        }
        return {0,0};
    }
};
