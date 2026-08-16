class Solution {
private:
    bool noOverlap(vector<int>& interval1, vector<int>& interval2) {
        if(interval2[0] >= interval1[1] || interval1[0] >= interval2[1]) {
            return true;
        }
        return false;
    }
public:
    int eraseOverlapIntervalsHelper(int i, int prev, vector<vector<int>>& intervals, vector<int> &dp) {
        int n = intervals.size();
        if(i >= n) {
            return 0;
        }
        if(dp[i] != -1000000) {
            return dp[i];
        }
        int cur = -1000000;
        if(prev == -1 || noOverlap(intervals[i], intervals[prev])) {
            cur = max(cur, 1 + eraseOverlapIntervalsHelper(i+1, i, intervals, dp));
        }
        cur = max(cur, eraseOverlapIntervalsHelper(i+1, prev, intervals, dp));
        dp[i] = cur;
        return cur;
    } 
    static bool customSort(vector<int> & v1, vector<int> & v2) {
        return v1[1] < v2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> dp(n+1, -1000000);
        sort(intervals.begin(), intervals.end(), customSort);
        //vector<int> prev = {-1000000, -1000000};
        int d = eraseOverlapIntervalsHelper(0, -1, intervals, dp);
        int maxPos = 0;
        return n-d;
        /*set<pair<int,int> > unique;
        for(int k = 0; k < n; k++) {
            unique.insert({intervals[k][0], intervals[k][1]});
        }
        int ans = n - unique.size();
        map<int, int> numberLine;
        vector<int> overlap(n, 0);
        int i = 0, j = 0, curEnd = -1e6; 
        int sum = 0;
        priority_queue<int> maxOverlaps;
        while(i < n) {
            curEnd = intervals[i][1];
            while(i+1 < n && intervals[i][0] == intervals[i+1][0] && intervals[i][1] == intervals[i+1][1]) {
                i++;
            }
            while(j < n && intervals[j][0] < curEnd) {
                overlap[j] += j-1-i+1;
                j++;
            }
            overlap[i] += j-i-1;
            maxOverlaps.push(overlap[i]);
           // cout<<overlap[i]<<" ";
            sum += overlap[i];
            i++;
        }
        //cout<<endl;
        while(sum > 0 && maxOverlaps.size() > 0) {
            int top = maxOverlaps.top();
            cout<<sum<<" "<<top<<endl;
            sum -= top*2;
            ans++;
            maxOverlaps.pop();
        }
        for(int i = 0; i < n; i++) {
            //if(!numberLine.contains(intervals[i][0]) || numberLine[intervals[i][0]] == 1)
            numberLine[intervals[i][0]]++;
            numberLine[intervals[i][1]]--;
        }
        int ans = 0, prev = 0, curMax = 0;
        for(auto it:numberLine) {
            prev += it.second;
            curMax = max(curMax, prev);
            if(prev == 0) {
                ans += curMax-1;
            }
        }*/
        //cout<<sum;
       // return ans;
    }
};
