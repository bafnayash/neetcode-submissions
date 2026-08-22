class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        for(int i = 1; i <= n; i++) {
            int cur = i&(i-1);
            int count = 1;
            while(cur > 0) {
                count++;
                cur = cur&(cur-1);
            }
            ans.push_back(count);
        }
        return ans;
    }
};
