class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>> > adj(n);
        for(int i = 0; i < flights.size(); i++) {
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        vector<vector<int> >  cost(n, vector<int> (k+2, 1e6));
        cost[src][0] = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= k; j++) {
                for(int z = 0; z < flights.size(); z++) {
                    int u = flights[z][0];
                    int v = flights[z][1];
                    int curCost = flights[z][2];
                    if(cost[v][j+1] > cost[u][j] + curCost) {
                        cost[v][j+1] = cost[u][j] + curCost;
                    }
                }
            }
        }
        int ans = 1e6;
        for(auto i: cost[dst]) {
            ans = min(i, ans);
        }
        if(ans == 1e6) {
            return -1;
        }
        return ans;
    }
    /*int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>> > adj(n);
        for(int i = 0; i < flights.size(); i++) {
            adj[flights[i][0]].push_back({flights[i][2], flights[i][1]});
        }
        vector<vector<int> >  cost(n, vector<int> (k+2, 1e6));
        cost[src][0] = 0;
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int> >> q;
        q.push({0, src, 0});
        set<int> vis;
        //int cur = 0;
        while(!q.empty()) {
            int temp = q.size();
            auto [curCost, curSrc, curStops]  = q.top();
            q.pop();
            if(curStops == k+1) {
                continue;
            }
            for(int i = 0; i < adj[curSrc].size(); i++) {
                if(cost[adj[curSrc][i].second][curStops+1] > cost[curSrc][curStops] + adj[curSrc][i].first) {
                    cost[adj[curSrc][i].second][curStops+1] = cost[curSrc][curStops] + adj[curSrc][i].first;
                    q.push({cost[adj[curSrc][i].second][curStops+1], adj[curSrc][i].second, curStops+1});
                }
            }
        }
        int ans = 1e6;
        for(auto i: cost[dst]) {
            ans = min(i, ans);
        }
        if(ans == 1e6) {
            return -1;
        }
        return ans;
    }*/
};
