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
    int ans = INT_MIN;
    void dfs(TreeNode* root, unordered_map<TreeNode*, pair<int,int> > &dp) {
        if(!root) {
            return;
        }
        if(!root->left && !root->right) {
            dp[root] = {INT_MIN, root->val};
        } else if(root->left && root->right) {
            dfs(root->left, dp);
            dfs(root->right, dp);
            ans = max(ans, root->val+dp[root->left].second+dp[root->right].second);
            int includedCur = root->val+max(dp[root->left].second, dp[root->right].second);
            includedCur = max(includedCur, root->val);
            int notIncludedCur = max(dp[root->left].first, dp[root->right].first);
            notIncludedCur = max(notIncludedCur, max(dp[root->left].second, dp[root->right].second));
            dp[root] = {notIncludedCur, includedCur};
        } else if(root->left) {
            dfs(root->left, dp);
            int includedCur = max(root->val+dp[root->left].second, root->val);
            int notIncludedCur = max(dp[root->left].second, dp[root->left].first);
            dp[root] = {notIncludedCur, includedCur};
        } else {
            dfs(root->right, dp);
            int includedCur = max(root->val+dp[root->right].second, root->val);
            int notIncludedCur = max(dp[root->right].second, dp[root->right].first);
            dp[root] = {notIncludedCur, includedCur};
        }
        //cout<<root->val<<" "<<dp[root].first<<" "<<dp[root].second<<endl;
    }
    int maxPathSum(TreeNode* root) {
        unordered_map<TreeNode*, pair<int,int> > dp;
        dfs(root, dp);
        return max(ans, max(dp[root].first, dp[root].second));
    }
};
