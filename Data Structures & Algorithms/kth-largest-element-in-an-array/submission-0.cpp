class Solution {
public:
    void quickSort(int l, int r, int k, vector<int>& nums) {
        int pivot = nums[r];
        int i = l;
        if (l > r) {
            return;
        }
        for(int j = l; j < r; j++) {
            if(nums[j] >= pivot) {
                swap(nums[j], nums[i]);
                i++;
            }
        }
        swap(nums[i], nums[r]);
        if(i+1 == k) {
            return;
        } else if(i+1 < k) {
            l = i+1;
            quickSort(l, r, k, nums);
        } else {
            r = i-1;
            quickSort(l, r, k, nums);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        quickSort(0, nums.size()-1, k, nums);
        return nums[k-1];
    }
};
