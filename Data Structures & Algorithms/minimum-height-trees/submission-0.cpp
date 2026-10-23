class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(): val(0), left(nullptr), right(nullptr) {};
        TreeNode(int x): val(x), left(nullptr), right(nullptr) {};
        TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l), right(r) {};
    };
    int getHeight(int x, vector<vector<int> > & adj, set<int> &vis) {
        int ans = 0;
        for(int i = 0; i < adj[x].size(); i++) {
            if(!vis.contains(adj[x][i])) {
                vis.insert(adj[x][i]);
                ans = max(ans, 1 + getHeight(adj[x][i], adj, vis));
            }
        }
        return ans;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int> > adj(n+1);
        for(int i = 0; i < n-1; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        if(n == 1) {
            return {0};
        }
        vector<int> heights(n+1, 0);
        int mi = 1e7;
        for(int i = 0; i < n; i++) {
            set<int> vis;
            vis.insert(i);
            heights[i] = getHeight(i, adj, vis);
            mi = min(heights[i], mi);
        }
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(heights[i] == mi) {
                ans.push_back(i);
            }
        }
        return ans;
    }
}; 