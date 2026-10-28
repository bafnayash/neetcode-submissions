class Solution {
public:
    map<vector<int>, int> dp;
    int maxCoinsHelper(int i, int j, vector<int> & nums, vector<vector<int> > & dp) {
        int n = nums.size();
        if(i < 0 || i > j || j >= n) {
            return 0;
        }
        if(dp[i][j]) {
            return dp[i][j];
        }
        /*//}
        int temp = i-1;
        int left = 1;
        /*while(temp >= 0 && vis.contains(temp)) {
            temp--;
        }
        if(temp >= 0) {
            left = nums[temp];
        }
        int right = 1;
        temp = i+1;
        while(temp < n && vis.contains(temp)) {
            temp++;
        }
        if(temp < n) {
            right = nums[temp];
        }*/
        int ans = 0;
        for(int k = i; k <= j; k++) {
            int left = (i-1 >= 0) ? nums[i-1] : 1;
            int right = (j+1 < n) ? nums[j+1] : 1;
            ans = max(ans, left*nums[k]*right + maxCoinsHelper(i, k-1, nums, dp) + maxCoinsHelper(k+1, j, nums, dp));
        }
        dp[i][j] = ans;
        /*if(!vis.contains(cur)) {
            int ele = cur[i];
            vis.insert(cur);
            ans = max(ans, maxCoinsHelper(i+1, vis, cur, nums));
            ans = max(ans, maxCoinsHelper(i-1, vis, cur, nums));
            cur.erase(cur.begin() + i);
            ans = max(ans, left*ele*right + maxCoinsHelper(i-1, vis, cur, nums));
            ans = max(ans, left*ele*right + maxCoinsHelper(i, vis, cur, nums));
            cur.insert(cur.begin()+i, ele);
            //
        } */
        //
        
        //dp[cur] = ans;
        return ans;
    }
    int maxCoins(vector<int>& nums) {
        set<vector<int> > vis;
        vector<int> cur(nums);
        //vis.insert(cur);
        int n = nums.size();
        vector<vector<int> > dp(n, vector<int> (n, 0));
        return maxCoinsHelper(0, n-1, nums, dp);
    }
};
