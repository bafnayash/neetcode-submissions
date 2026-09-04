class Solution {
public:
    static bool comp(pair<int, int> &p1, pair<int, int> &p2) {
        if(p1.first == p2.first) {
            return p1.second < p2.second;
        }
        return p1.first < p2.first;
    }
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<pair<int, int> > q;
        int n = temperatures.size();
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++) {
            q.push_back({temperatures[i], i});
        }
        sort(q.begin(), q.end(), comp);
        set<int> pos;
        int j = n-1;
        while(j >= 0) {
            pair<int, int> p1 = q[j];
            auto it = pos.upper_bound(p1.second);
            if(it != pos.end()) {
                ans[p1.second] = *it-p1.second;
            }
            j--;
            int temp = j;
            while(j >= 0 && q[j].first == p1.first) {
                auto it2 = pos.upper_bound(q[j].second);
                if(it2 != pos.end()) {
                    ans[q[j].second] = *it2 - q[j].second;
                }
                j--;
            }
            //j--;
            pos.insert(p1.second);
            for(int k = j+1; k <= temp; k++) {
                pos.insert(q[k].second);
            }
            //q.pop();
            /*if(!q.empty()) {
                pair<int, int> p2 = q.top();
                ans[p2.second] = (p1.second > p2.second) ? p1.second - p2.second : 0;
            }*/
        }
        return ans;
    }
};
