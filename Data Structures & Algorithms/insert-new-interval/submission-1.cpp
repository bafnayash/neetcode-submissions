class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int i = 0;
        vector<vector<int> > ans;
        while(i < n && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }
        int newSt = -1;
        if(i < n) {
            newSt = min(intervals[i][0], newInterval[0]);
            int j = i;
            while(j < n && newInterval[1] >= intervals[j][0]) {
                j++;
            }
            int newEnd = -1;
            newEnd = max(j >= 1 ? intervals[j-1][1] : 0, newInterval[1]);
            ans.push_back({newSt, newEnd});
            while(j < n) {
                ans.push_back(intervals[j]);
                j++;
            }
        } else {
            ans.push_back(newInterval);
        }
        return ans;
    }
};
