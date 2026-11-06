class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int> q;
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(!q.empty() && i >= k && q.top() == nums[i-k]) {
                q.pop();
            }
            while(!q.empty() && nums[i] > q.top()) {
                q.pop();
            }
            q.push(nums[i]);
            if(i >= k-1) {
                ans.push_back(q.top());
            }
        }
        return ans;
    }
};
