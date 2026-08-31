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
    bool ans = true;
    int dfs(TreeNode* root) {
        if(!root || !ans) {
            return 0;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        if(abs(left-right) > 1) {
            ans = false;
            return 0;
        }
        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        if(!root) {
            return true;
        }
        dfs(root);
        return ans;
    }
};
