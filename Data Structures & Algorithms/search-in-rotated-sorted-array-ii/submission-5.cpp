class Solution {
public:
    int ans = false;
    int findRotation(int l, int h, vector<int>& nums, int left, int target) {
        while(l <= h) {
            int mid = l + (h-l)/2;
            if(nums[mid] == target) {
                ans = true;
                return 0;
            }
            if(nums[mid] > nums[l]) {
                if(target > nums[l] && target < nums[mid])
                    h = mid-1;
                else 
                    l = mid+1;
            } else if(nums[mid] == nums[l]) {
                l++;
            } else {
                if(target > nums[mid] && target < nums[h])
                    l = mid+1;
                else 
                    h = mid-1;
                //l = mid+1;
            }
        }
        return l;
    }
    int bs(int l, int h, vector<int>& nums, int target) {
        while(l < h) {
            int mid = l + (h-l+1)/2;
            if(nums[mid] == target) {
                ans = true;
                return 0;
            }
            if(nums[mid] < target) {
                l = mid;
            } else {
                h = mid-1;
            }
        }
        return l;
    }
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        ans = false;
        if(n == 1) {
            return nums[0] == target;
        }
        int rotate = findRotation(0, n-1, nums, nums[0], target);
        cout<<rotate<<" "<<endl;
        int op1 = bs(0, rotate, nums, target);
        int op2 = bs(min(rotate+1,n-1), n-1, nums, target);
        return ans;
    }
};