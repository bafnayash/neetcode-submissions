/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int ans;
    void dfs(TreeNode* root, priority_queue<int> q) {
        if(!root) {
            return;
        }
        if(q.empty() || q.top() <= root->val) {
            ans++;
        }
        q.push(root->val);
        dfs(root->left, q);
        dfs(root->right, q);
    }
    int goodNodes(TreeNode* root) {
        ans = 0;
        priority_queue<int> q;
        dfs(root, q);
        return ans;
    }
};
