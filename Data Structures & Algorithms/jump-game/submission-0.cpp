class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int> reachable;
        reachable.push(0);
        for(int i = 0; i < n; i++) {
            if(reachable.top() >= i) {
                reachable.push(i+nums[i]);
            }
        }
        if(reachable.top() >= n-1) {
            return true;
        }
        return false;
    }
};
