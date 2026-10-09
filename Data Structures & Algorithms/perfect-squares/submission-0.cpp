class Solution {
public:
    int ans;
    int numSquaresHelper(int i, int target, int count, vector<int> &nums, vector<vector<int> > & dp) {
        if(target == 0) {
            ans = min(count, ans);
            return 1;
        }
        if(i < 0 || target < 0) {
            return 0;
        }
        if(dp[i][target] != -1) {
            return dp[i][target];
        }
        int op1 = numSquaresHelper(i, target - nums[i], count+1, nums, dp);
        int op2 = numSquaresHelper(i-1, target, count, nums, dp);
        dp[i][target] = op1 + op2;
        return dp[i][target]; 
    }
    int numSquares(int n) {
        vector<int> nums;
        for(int j = 1; j*j <= n; j++) {
            nums.push_back(j*j);
        }
        ans = 1e6;
        vector<vector<int> > dp(nums.size(), vector<int> (n+1, -1));
        numSquaresHelper(nums.size()-1, n, 0, nums, dp);
        return ans;
    }
};