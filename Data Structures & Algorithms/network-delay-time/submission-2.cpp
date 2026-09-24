class Solution {
public:
    static bool comp(pair<int,int> & p1, pair<int,int> & p2) {
        return p1.first < p2.first;
    }   
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int> > > adj(n+1);
        for(int i = 0; i < times.size(); i++) {
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > q;
        vector<int> cost(n+1, 1e6);
        cost[k] = 0;
        q.push({0, k});
        int ans = -1;
        //set<int> vis;
        while(!q.empty()) {
            auto [curCost, src] = q.top();
            q.pop();
            //vis.insert(src);
            cout<<src<<" "<<curCost<<endl;
            //vis.insert(src);
            //ans += curCost;
            for(int i = 0; i < adj[src].size(); i++) {
                if(cost[adj[src][i].first] > cost[src] + adj[src][i].second) {
                    cost[adj[src][i].first] = cost[src] + adj[src][i].second;
                    q.push({adj[src][i].second, adj[src][i].first});
                }
            }
        }
        for(int i = 1; i <= n; i++) {
            if(i != k && cost[i] != 1e6) {
                ans = max(ans, cost[i]);
            } else if(i != k) {
                return -1;
            }
        }
        return ans;
    }
};
