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
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        map<int, int> overlap;
        for(int i = 0; i < n; i++) {
            overlap[intervals[i].start]++;
            overlap[intervals[i].end]--;
        }
        int sum = 0, ans = 0;
        for(auto it:overlap) {
            sum += it.second;
            ans = max(ans, sum);
        }
        return ans;
    }
};
