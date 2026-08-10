class Solution {
public:
    int binarySearchRot(int l, int h, vector<int> &nums, int cmp) {
        while(l<h) {
            int mid = l + (h-l)/2;
            if(nums[mid] >= cmp) {
                l = mid + 1;
            } else {
                h = mid;
            }
        }
        return h;
    }
    int binarySearch(int l, int h, vector<int> &nums, int target) {
        while(l<h) {
            int mid = l + (h-l)/2;
            if(nums[mid] >= target) {
                h = mid;
            } else {
                l = mid + 1;
            }
        }
        return h;
    }
    int search(vector<int>& nums, int target) {
        int pos = binarySearchRot(0, nums.size()-1, nums, nums[0]);
        if(nums[pos] > nums[0]) {
            pos = 0;
        }
        int search1 = binarySearch(0, pos, nums, target);
        if(nums[search1] == target)
            return search1;
        int search2 = binarySearch(pos, nums.size()-1, nums, target);
        if(nums[search2] == target)
            return search2;
        return -1;            
    }
};
