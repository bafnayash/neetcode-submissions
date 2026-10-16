class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int cnt = 0;
        int ans = 1;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            if(nums[i] > cnt) {
                sum += nums[i];
                cnt++;
                cout<<sum<<" "<<cnt<<endl;
                if(sum > cnt*(cnt+1)/2) {
                    //int temp = sum - nums[i];
                    return cnt;
                }
            }
        }
        return cnt == 0 ? ans : cnt+1;   
    }
};