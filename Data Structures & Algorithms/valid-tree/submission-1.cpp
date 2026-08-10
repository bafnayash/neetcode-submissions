class Solution {
public:
    unordered_set<int> global;
    bool dfs(int v, int prev, unordered_set<int> vis, vector<vector<int> > & adjList) {
        int n = adjList[v].size();
        vis.insert(v);
        global.insert(v);
        bool ans = true;
        for(int i = 0; i < n; i++) {
            int cur = adjList[v][i];
            if(prev != cur) {
                if(vis.contains(cur)) {
                    return false;
                }
                //vis.insert(cur);
                ans = ans && dfs(cur, v, vis, adjList);
            }
        }
        return ans;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int> > adjList(n);
        for(int i = 0; i < edges.size(); i++) {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        if(n == 0) {
            return true;
        }
        unordered_set<int> vis;
        bool ans = dfs(0, 1e6, vis, adjList);;
        for(int i = 0; i < n; i++) {
            if(!global.contains(i)) {
                return false;
            }
            //cout<<i <<" "<<ans<<endl;
        }
        return ans;        
    }
};
