class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int> > ans;
        int n = intervals.size();
        int i = 0;
        sort(intervals.begin(), intervals.end());
        while(i < n) {
            int st = intervals[i][0], en = intervals[i][1];
            while(i+1 < n && intervals[i+1][0] <= en) {
                en = max(en, intervals[i+1][1]);
                i++;
            }
            ans.push_back({st, en});
            i++;
        }
        return ans;
    }
};
