class Solution {
public:
    /*int bs(int l, int h, int val, vector<vector<int>> & intervals) {
        while(l < h) {
            int mid = l + (h-l)/2;
            if(intervals[mid][1] < val) {
                l = mid+1;
            } else {
                h = mid;
            }
        }
        return h;
    }
    int bs2(int l, int h, int val, vector<vector<int>> & intervals) {
        while(l < h) {
            int mid = l + (h-l+1)/2;
            if(intervals[mid][0] <= val) {
                l = mid;
            } else {
                h = mid-1;
            }
        }
        return l;
    }
    static bool comparator(vector<int> & v1, vector<int> &v2) {
        if(v1[1] != v2[1]) {
            return v1[1] < v2[1];
        }
        return v1[1]-v1[0] < v2[1]-v2[0];
    }
    static bool comparator2(vector<int> & v1, vector<int> &v2) {
        if(v1[0] != v2[0]) {
            return v1[0] < v2[0];
        }
        return v1[1]-v1[0] < v2[1]-v2[0];
    }
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size();
        vector<vector<int> > dup(intervals.begin(), intervals.end());
        sort(intervals.begin(), intervals.end(), comparator);
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++) {
            int idx = bs(0, n-1, queries[i], intervals);
            if(intervals[idx][0] <= queries[i] && intervals[idx][1] >= queries[i]) {
                ans.push_back(intervals[idx][1]-intervals[idx][0]+1);
            } else {
                ans.push_back(-1);
            }
        }
        sort(dup.begin(), dup.end(), comparator2);
        for(int i = 0; i < queries.size(); i++) {
            int idx = bs2(0, n-1, queries[i], dup);
            int temp = dup[idx][1]-dup[idx][0]+1;
            if(ans[i] == -1 && dup[idx][0] <= queries[i] && dup[idx][1] >= queries[i]) {
                ans[i] = temp;
            } else if(dup[idx][0] <= queries[i] && dup[idx][1] >= queries[i]) {
                ans[i] = min(ans[i], temp);
            }
        }
        return ans;
    }
    long long getNext(long long x) {
        return x + (-x&x);
    }
    void updateTree(vector<long long> & tree, long long low, long long high, long long val) {
        long long mx = tree.size();
        while(low <= high) {
            tree[low] = (tree[low] != -1) ? min(tree[low], val) : val;
            low = getNext(low);
        }
    }
    long long query(long long x, vector<long long> & tree) {
        long long ans = 1e8;
        while(x >= 0) {
            long long comp = (tree[x] >= 0) ? tree[x] : 1e8; 
            ans = min(ans, comp);
            x -= x&(-x);
        }
        return ans;
    }*/
    struct comp {
        bool operator() (pair<int,int> & p1, pair<int,int> & p2) {
            return p1.second - p1.first > p2.second - p2.first; 
        }
    };
    int bsStart(int l, int h, int start, vector<pair<int,int> > & queries) {
        while(l < h) {
            int mid = l + (h-l)/2;
            if(queries[mid].first >= start) {
                h = mid;
            } else {
                l = mid+1;
            }
        }
        return h;
    }
    int bsEnd(int l, int h, int end, vector<pair<int,int> > & queries) {
        while(l < h) {
            int mid = l + (h-l+1)/2;
            if(queries[mid].first <= end) {
                l = mid;
            } else {
                h = mid-1;
            }
        }
        return l;
    }
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size();
        /*long long mx = 0;
        for(int i = 0; i < n; i++) {
            mx = max(mx, (long long)intervals[i][1]);
        }
        vector<long long> BIT(mx+1, -1);
        for(int i = 0; i < n; i++) {
            long long range = intervals[i][1] - intervals[i][0] + 1;
            updateTree(BIT, intervals[i][0], intervals[i][1], range);
        }
        for(int i = 0; i <= mx; i++) {
            cout<<BIT[i]<<" ";
        }
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++) {
            long long res = query(queries[i], BIT);
            if(queries[i] <= mx && res < 1e8)
                ans.push_back(res);
            else {
                ans.push_back(-1);
            }
        }
        return ans;*/
        int m = queries.size();
        vector<int> ans(m, -1);
        priority_queue<pair<int,int>, vector<pair<int,int> >, comp> q;
        for(int i = 0; i < n; i++) {
            q.push({intervals[i][0], intervals[i][1]});
        }
        vector<pair<int,int> > queriesSorted;
        for(int i = 0; i < m; i++) {
            queriesSorted.push_back({queries[i], i});
        }
        sort(queriesSorted.begin(), queriesSorted.end());
        while(!q.empty()) {
            auto [start, end] = q.top();
            q.pop();
            int startMatch = bsStart(0, m-1, start, queriesSorted);
            int endMatch = bsEnd(0, m-1, end, queriesSorted);
            for(int i = startMatch; i <= endMatch; i++) {
                int pos = queriesSorted[i].second;
                int query = queriesSorted[i].first;
                if(ans[pos] == -1 && query >= start && query <= end) {
                    ans[pos] = end-start+1;
                }
            }
        }
        return ans;
    }
};
