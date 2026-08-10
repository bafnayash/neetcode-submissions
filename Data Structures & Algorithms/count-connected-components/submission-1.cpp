class Solution {
private:
    set<int> vis;
public:
    void dfs(int v, int parent, vector<vector<int> >& adjList) {
        vis.insert(v);
        for(int i = 0; i < adjList[v].size(); i++) {
            if(!vis.contains(adjList[v][i]) && adjList[v][i] != parent) {
                dfs(adjList[v][i], v, adjList);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int> > adjList(n);
        int m = edges.size();
        for(int i = 0; i < m; i++) {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(!vis.contains(i)) {
                dfs(i, -1, adjList);
                ans++;
            }
        }
        return ans;
    }
};
