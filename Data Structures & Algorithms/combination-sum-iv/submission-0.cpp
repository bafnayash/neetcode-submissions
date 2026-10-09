class Solution {
public:
    int all;
    int combinationSum4Helper(int i, int target, vector<int> & nums, vector<vector<int> > &dp) {
        if(target == 0) {
            return 1;
        }
        int n = nums.size();
        if(i < 0 || i >= n || target < 0) {
            return 0;
        }
        if(all >= 10000) {
            return 0;
        }
        if(dp[i][target] != -1) {
            return dp[i][target];
        }
        all++;
        int op1 = combinationSum4Helper(i, target - nums[i], nums, dp);
        cout<<i<<" "<<target<<endl;
        int op2 = combinationSum4Helper(i-1, target, nums, dp);
        cout<<i<<" "<<target<<endl;
        int op3 = combinationSum4Helper(i+1, target, nums, dp);
        cout<<i<<" "<<target<<" 3 "<<endl;
        dp[i][target] = op1 + op2 + op3;
        return dp[i][target];
    }
    int combinationSum4Helper2(int i, int target, vector<int> & nums, vector<vector<int> > &dp) {
        if(target == 0) {
            return 1;
        }
        int n = nums.size();
        if(i >= n || target < 0) {
            return 0;
        }
        if(dp[i][target] != -1) {
            return dp[i][target];
        }
        int op1 = combinationSum4Helper(i, target - nums[i], nums, dp);
        int op2 = combinationSum4Helper(i+1, target, nums, dp);
        dp[i][target] = op1 + op2;
        return dp[i][target];
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        all = 0;
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for(int i = 0; i <= target; i++) {
            for(int j = 0; j < n; j++) {
                if(i + nums[j] <= target) {
                    dp[i+nums[j]] += dp[i];
                }
            }
        }
        return dp[target];
        //return combinationSum4Helper(n-1, target, nums, dp);
    }
};