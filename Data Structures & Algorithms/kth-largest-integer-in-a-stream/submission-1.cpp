class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int> > q;
    KthLargest(int k, vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i < n) {
            q.push(nums[i]);
            i++;
        }
        while(q.size() > k) {
            q.pop();
        }
        while(q.size() < k) {
            q.push(-1e6);
        }
    }
    
    int add(int val) {
        q.push(val);
        q.pop();
        return q.top();
    }
};
