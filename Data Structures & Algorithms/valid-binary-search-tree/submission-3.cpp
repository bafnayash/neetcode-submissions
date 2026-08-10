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
    int mxEle(TreeNode* root, bool & ans) {
        if(!root) 
            return 0;
        else if(root->left && root->right) {
            int left = mxEle(root->left, ans);
            int right = mxEle(root->right, ans);
            if(left >= root->val || right <= root->val)
                ans = false;
            return max(max(left, right), root->val);
        } else if(root->left) {
            int left = mxEle(root->left, ans);
            if(left >= root->val)
                ans = false;
            return max(root->val, left);
        } else if(root->right){
            int right = mxEle(root->right, ans);
            if(right <= root->val)
                ans = false;
            return max(root->val, right);
        } else {
            return root->val;
        }
    }
    int minEle(TreeNode* root, bool & ans) {
        if(!root) 
            return 1e9;
        else if(root->left && root->right) {
            int left = minEle(root->left, ans);
            int right = minEle(root->right, ans);
            if(left >= root->val || right <= root->val)
                ans = false;
            return min(min(left, right), root->val);
        } else if(root->left) {
            int left = minEle(root->left, ans);
            if(left >= root->val)
                ans = false;
            return min(root->val, left);
        } else if(root->right){
            int right = minEle(root->right, ans);
            if(right <= root->val)
                ans = false;
            return min(root->val, right);
        } else {
            return root->val;
        }
    }
    bool isValidBST(TreeNode* root) {
        bool ans = true;
        mxEle(root, ans);
        minEle(root, ans);
        return ans;
    }
};
