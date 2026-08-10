class Solution {
public:
    int binarySearch(int l, int h, vector<int> &nums, int cmp) {
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
    //int ans = 1e9;
    void divideAndConquer(int l, int h, vector<int> &nums, int cmp, int &ans) {
        int mid = l + (h-l)/2;
        if(nums[mid] <= cmp) {
            ans = min(ans, nums[mid]);
        }
        if(l==h)
            return;
        //cout<<l<<" "<<h<<endl;
        divideAndConquer(l, mid, nums, cmp, ans);
        divideAndConquer(mid+1, h, nums, cmp, ans);
    }
    int findMin(vector<int> &nums) {
        int pos = binarySearch(0, nums.size()-1, nums, nums[0]);
        if(nums[pos] <= nums[0])
            return nums[pos];   
        return nums[0];
    }
};
