class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = flowers.size();
        int m = people.size();
        //map<pair<int,int>, int > intervals;
        sort(flowers.begin(), flowers.end());
        //intervals[{flowers[0][0], flowers[0][1]}] = 1;
        map<int, int> interval;
        for(int i = 0; i < n; i++) {
            interval[flowers[i][0]]++;
            interval[flowers[i][1]+1]--;
        }
        map<int,int> prefixSum;
        int cur = 0;
        for(auto it:interval) {
            prefixSum[it.first] = it.second + cur;
            cur += it.second;
        }
        vector<int> ans;
        for(int i = 0; i < m; i++) {
            auto it = prefixSum.lower_bound(people[i]);
            if(it->first == people[i]) {
                ans.push_back(it->second);
            } else if(it == prefixSum.begin()) {
                ans.push_back(0);
            } else {
                //it--;
                ans.push_back(prev(it)->second);
            }
        }
        return ans;
        /*
        for(int i = 1; i < n; i++) {
            auto it = intervals.lower_bound(flowers[i][0]);
            if(it != intervals.begin() && prev(it)->first.second >= flowers[i][0]) {
                it--;
            }
            map<pair<int,int>,int > temp;
            int start = it->first.first, end = max(it->first.second, flowers[i][1]), count = it->second;
            while(end >= it->first.first) {
                //end = min(it->first.second, flowers[i][0])-1;
                if( >= start) {
                    temp[{start, end}] = it->second;
                }
                start = min(it->first.second, flowers[i][0]);
                end = it->first.second;
                intervals.erase(it++);
            }
        }*/
    }
};
