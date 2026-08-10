class Solution {
public:
    unordered_set<int> global;
    bool dfs(int v, unordered_set<int> vis, vector<vector<int> > & adjList) {
        int n = adjList[v].size();
        vis.insert(v);
        global.insert(v);
        bool ans = true;
        for(int i = 0; i < n; i++) {
            int cur = adjList[v][i];
            if(vis.contains(cur)) {
                return false;
            }
            //vis.insert(cur);
            ans = ans && dfs(cur, vis, adjList);
        }
        return ans;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > vertices(numCourses);
        int n = prerequisites.size();
        if(n == 0) {
            return true;
        }
        int m = prerequisites[0].size();
        for(int i = 0; i < n; i++) {
            vertices[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        bool ans = true;
        for(int i = 0; i < numCourses; i++) {
            unordered_set<int> vis;
            if(!global.contains(i)) {
                bool temp = dfs(i, vis, vertices);
                ans = ans && temp;
            }
            //cout<<i <<" "<<ans<<endl;
        }
        return ans;
    }
};
