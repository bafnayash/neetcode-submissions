class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(!q.empty() && i >= k && q.front() == nums[i-k]) {
                q.pop_front();
            }
            if(nums[i] > q.front()) {
                while(!q.empty() && nums[i] > q.front()) {
                    q.pop_front();
                }
                q.push_front(nums[i]);
            } else {
                while(!q.empty() && nums[i] > q.back()) {
                    q.pop_back();
                }
                q.push_back(nums[i]);
            }
            if(i >= k-1) {
                ans.push_back(q.front());
            }
        }
        return ans;
    }
};
