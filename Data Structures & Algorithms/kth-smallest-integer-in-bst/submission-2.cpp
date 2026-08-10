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
    int treeLen(TreeNode* root, unordered_map<TreeNode*, pair<int, int> > & len, int k, int cur) {
        if(!root) {
            return 0;
        } else if(!root->left && !root->right) {
            len[root] = {0,0};
            if(k == cur+1) {
                return root->val;
            }
            return 0;
        } else if(root->left && root->right) {
            int res = treeLen(root->left, len, k, cur);
            if(res)
                return res;
            int left = 1+len[root->left].first+len[root->left].second;
            if(k == cur+left+1) {
                return root->val;
            }
            cur += left+1;
            res = treeLen(root->right, len, k, cur);
            if(res)
                return res;
            int right = 1+len[root->right].first + len[root->right].second;
            len[root] = {left, right};
        } else if(root->left) {
            int res = treeLen(root->left, len, k, cur);
            if(res)
                return res;
            int left = 1+len[root->left].first + len[root->left].second;
            if(k == cur+left+1) {
                return root->val;
            }
            len[root] = {left, 0};
        } else {
            if(k == cur+1) {
                return root->val;
            }
            cur += 1;
            int res = treeLen(root->right, len, k, cur);
            if(res)
                return res;
            int right = 1 + len[root->right].first + len[root->right].second;
            len[root] = {0, right};
        }
        return 0;
    }
    /*int kthSmallestHelper(TreeNode* root, int k, int cur, unordered_map<TreeNode*, pair<int, int> > &len) {
        if(!root) {
            return 0;
        } 
        int left = len[root].first;
        int right = len[root].second;
        if(k == cur+left+1) {
            return root->val;
        } else if(k <= left) {
            return kthSmallestHelper(root->left, k, cur, len);
        } else if(k > left) {
            cur += left+1;
            return kthSmallestHelper(root->right, k, cur, len);
        }
    }*/
    int kthSmallest(TreeNode* root, int k) {
        unordered_map<TreeNode*, pair<int, int> > len;
        //treeLen(root, len);
        return treeLen(root, len, k, 0);
    }
};
