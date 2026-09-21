class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>> > adj(n);
        for(int i = 0; i < flights.size(); i++) {
            adj[flights[i][0]].push_back({flights[i][2], flights[i][1]});
        }
        vector<vector<int> >  cost(n, vector<int> (k+2, 1e6));
       // vector<vector<int> > dist(n+1, vector<);
        //dist[src] = 0;
        cost[src][0] = 0;
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int> >> q;
        q.push({0, src, 0});
        //vector<int> level(n, 1e6);
        //level[src] = 0;
       // set<pair<int,int> > vis;
        set<int> vis;
        //int cur = 0;
        while(!q.empty()) {
            int temp = q.size();
            auto [curCost, curSrc, curStops]  = q.top();
            //cout<<fr<<"\n";
            //vis;
            /*if(curSrc == dst) {
                return curCost;
            }*/
            q.pop();
            if(curStops == k+1) {
                continue;
            }
            for(int i = 0; i < adj[curSrc].size(); i++) {
            //level[adj[fr][i].second] = min(level[fr] + 1, level[adj[fr][i].second]);
                if(cost[adj[curSrc][i].second][curStops+1] > cost[curSrc][curStops] + adj[curSrc][i].first) {
                    cost[adj[curSrc][i].second][curStops+1] = cost[curSrc][curStops] + adj[curSrc][i].first;
                    q.push({cost[adj[curSrc][i].second][curStops+1], adj[curSrc][i].second, curStops+1});
                }
                /*for(auto j : cost[fr]) {
                    //if(!vis.contains(adj[fr][i].second)) {
                      //  vis.insert({adj[fr][i].second, j.second+1});
                       // q.push({adj[fr][i].first, adj[fr][i].second});
                   // }
                    cost[adj[fr][i].second].push_back({j.first + adj[fr][i].first, j.second+1});
                }*/
            }
            //vis.insert(fr);
        }
        int ans = 1e6;
        for(auto i: cost[dst]) {
            //cout<<i.first<<" "<<i.second<<endl;
            ans = min(i, ans);
        }
        if(ans == 1e6) {
            return -1;
        }
        return ans;
    }
};
