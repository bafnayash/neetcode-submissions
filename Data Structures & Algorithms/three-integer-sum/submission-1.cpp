class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        /*unordered_map<int, int> allNum;
        for(int i = 0; i < n; i++) {
            allNum[-nums[i]]++;
        } */
        sort(nums.begin(), nums.end());
        for(auto i:nums) {
            cout<<i<<" ";
        }
        set<vector<int> > triplets;
        for(int k = 0; k < n; k++) {
            int i = 0, j = n-1;
            while(i<j) {
                if(i == k) {
                    i++;
                } else if(j==k) {
                    j--;
                } else if(nums[i] + nums[j] < -nums[k]) {
                    i++;
                } else if(nums[i] + nums[j] > -nums[k]) {
                    j--;
                } else {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    triplets.insert(temp);
                    i++;
                    j--;
                }
            }
        }
        vector<vector<int> > ans;
        for(auto it:triplets) {
            ans.push_back(it);
        }
        return ans;
    }
};
