class Solution {
public:
    vector<string> ans;
    map<pair<string, string>, int> ticketCount;
    void dfs(string cur, unordered_map<string, vector<string> > & adj) {
        /*if(path.size() == ticketSize+1) {
            //ans = path;
            return true;
        } else if(path.size() >= ticketSize + 1) {
            return false;
        }
        bool ans = false;
        for(int i = 0; i < adj[cur].size(); i++) {
            if(vis[{cur, adj[cur][i]}] < ticketCount[{cur, adj[cur][i]}]) {
                vis[{cur, adj[cur][i]}]++;
                path.push_back(adj[cur][i]);
                ans |= dfs(adj[cur][i], ticketSize, path, vis, adj);
                if(ans) {
                    return true;
                }
                path.pop_back();
                vis.erase({cur, adj[cur][i]});
            }
        }*/
        while(!adj[cur].empty()) {
            string next = adj[cur].back();
            adj[cur].pop_back();
            dfs(next, adj);
        }
        ans.push_back(cur);
        //return ans;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        unordered_map<string, vector<string> > adj;
        for(int i = 0; i < n; i++) {
            adj[tickets[i][0]].push_back(tickets[i][1]);
        }
        for(auto it:adj) {
            //cout<<it.first<<" START ";
            for(int i = 0; i < it.second.size(); i++) {
                //cout<<it.second[i]<<" ";
                ticketCount[{it.first, it.second[i]}]++;
            }
            //cout<<endl;*/
            sort(it.second.begin(), it.second.end(), greater<string>());
            /*for(int i = 0; i < it.second.size(); i++) {
                cout<<it.second[i]<<" ";
            }*/
            adj[it.first] = it.second;
            //cout<<endl;
        }
        vector<string> path;
        map<pair<string,string>, int > vis;
        path.push_back("JFK");
        dfs("JFK", adj);
        reverse(ans.begin(), ans.end());
        return ans;
        /*priority_queue<string, vector<string>, greater<string> > q;
        q.push("JFK");
        map<pair<string, string>, int > vis;
        vector<string> ans;
        while(!q.empty()) {
            string curLoc = q.top();
            q.pop();
            ans.push_back(curLoc);
            for(int i = 0; i < adj[curLoc].size(); i++) {
                if(!vis.contains({curLoc, adj[curLoc][i]})) {
                    q.push(adj[curLoc][i]);
                    vis[{curLoc, adj[curLoc][i]}];
                }
            }
        }
        return ans;*/
    }
};
