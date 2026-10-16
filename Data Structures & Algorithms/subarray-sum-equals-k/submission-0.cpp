class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        //int sum = 0;
        int ans = 0;
        //int i = 0, st = 0;
        unordered_map<int,int> sum;
        int cur = 0;
        sum[0]++;
        for(int i = 0; i < n; i++) {
            cur += nums[i];
            if(sum.count(cur-k)) {
                ans += sum[cur-k];
            }
            sum[cur]++;
        }
        /*while(i < n) {
            if(sum == k) {
                ans++;
            } 
            if(sum < k) {
                sum += nums[i];
                i++;
            } else {
                sum -= nums[st];
                st++;
            }
        }*/
        return ans;
    }
};