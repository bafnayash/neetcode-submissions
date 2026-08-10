class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            count[nums[i]]++;
        }
        vector<pair<int, int> > v;
        for(auto it:count) {
            v.push_back({it.second, it.first});
        }
        sort(v.begin(), v.end());
        //cout<<v[0].first<<v[0].second;
        vector<int> ans;
        //cout<<v.size()<<" ";
        for(int i = v.size() - 1; i >= 0; i--) {
            //cout<<"YS";
            //cout<<v[i].first<<v[i].second;
            if(ans.size() == k)
                return ans;
            ans.push_back(v[i].second);
        }
        return ans;
    }
};
