class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> diff(n, 0);
        for(int i = 0; i < n; i++) {
            diff[i] = gas[i] - cost[i];
        }
        vector<int> suf(n+1, 0), pre(n+1, 0);
        int ans = -1, mx = -1e6;
        for(int i = n-1; i >= 0; i--) {
            suf[i] = suf[i+1] + diff[i];
        }
        pre[0] = diff[0];
        for(int i = 1; i < n; i++) {
            pre[i] = pre[i-1] + diff[i];
        }
        for(int i = 0; i < n; i++) {
            if((i == 0 && suf[i] >= 0) || (i > 0 && pre[i-1] + suf[i] >= 0)) {
                if(suf[i] > mx) {
                    mx = suf[i];
                    ans = i;
                }
            }
        }
        return ans;
    }
};
