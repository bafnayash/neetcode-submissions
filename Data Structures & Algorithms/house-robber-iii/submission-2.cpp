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
    map<pair<TreeNode*, bool>, int> dp;
    int robHelper(TreeNode* root, bool parTaken) {
        if(!root) {
            return 0;
        }
        if(dp.contains({root, parTaken})) {
            return dp[{root, parTaken}];
        }
        int ans = 0;
        if(!parTaken) {
            int op1 = robHelper(root->left, true);
            int op2 = robHelper(root->left, false);
            int op3 = robHelper(root->right, true);
            int op4 = robHelper(root->right, false);
            ans = max(op1 + op3 + root->val, op2 + op4);
            //cout<<root->val<<" "<<ans<<endl;
        } else {
            int op2 = robHelper(root->left, false);
            int op4 = robHelper(root->right, false);
            ans = op2 + op4;
            //cout<<root->val<<" "<<ans<<endl;
        }
        dp[{root, parTaken}] = ans;
        return ans;
    }
    int rob(TreeNode* root) {
        if(!root) {
            return 0;
        }
        
        return max(robHelper(root, true), robHelper(root, false));
    }
};