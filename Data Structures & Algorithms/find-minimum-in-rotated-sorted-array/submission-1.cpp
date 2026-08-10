class Solution {
public:
    /*int binarySearch(int l, int h, vector<int> &nums) {
        while(l<h) {
            int mid = l + (h-l)/2;
            if(nums[mid] <= nums[l] && nums[mid] <= nums[h]) {
                l = mid;
            } else {
                h = mid - 1;
            }
        }
        return l;
    }*/
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
        int ans = 1e9;
        divideAndConquer(0, nums.size()-1, nums, nums[0], ans);
        return ans;   
    }
};
