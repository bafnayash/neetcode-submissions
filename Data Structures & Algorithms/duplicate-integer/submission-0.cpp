class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> numbers;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(numbers.contains(nums[i]))
                return true;
            numbers.insert(nums[i]);
        }
        return false;
    }
};