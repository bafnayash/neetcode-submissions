class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        int n = stones.size();
        for(int i = 0; i < n; i++) {
            q.push(stones[i]);
        }
        while(q.size() > 1) {
            int e1 = q.top();
            q.pop();
            int e2 = q.top();
            q.pop();
            q.push(abs(e1-e2));
        }
        return q.top();
    }
};
