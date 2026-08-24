class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int mx = 0, sum = 0, mi = 1e6;
        for(int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            mi = min(mi, nums[i]);
            sum += nums[i];
        }
        if(sum == mx*(mx+1)/2) {
            if(mi > 0)
                return 0;
            else
                return mx+1;
        } else if(sum + mx + 1 == (mx+1)*(mx+2)/2) {
            return mx+1;
        } else {
            return mx*(mx+1)/2 - sum;
        }
    }
};
