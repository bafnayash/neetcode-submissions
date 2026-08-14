/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();
        map<int, int> numberLine;
        //sort(intervals.begin(), intervals.end());
        for(int i = 0; i < n; i++) {
            //if(!numberLine.contains(intervals[i][0]) || numberLine[intervals[i][0]] == 1)
            numberLine[intervals[i].start]++;
            numberLine[intervals[i].end]--;
        }
        int ans = 0, prev = 0, curMax = 0;
        for(auto it:numberLine) {
            prev += it.second;
            curMax = max(curMax, prev);
        }
        if(curMax > 1) {
            return false;
        }
        return true;
    }
};
