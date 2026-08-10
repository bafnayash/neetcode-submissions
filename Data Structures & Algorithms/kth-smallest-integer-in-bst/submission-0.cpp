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
    void treeLen(TreeNode* root, unordered_map<TreeNode*, pair<int, int> > & len) {
        if(!root) {
            return;
        } else if(!root->left && !root->right) {
            len[root] = {0,0};
            return;
        } else if(root->left && root->right) {
            treeLen(root->left, len);
            treeLen(root->right, len);
            int left = 1+len[root->left].first+len[root->left].second;
            int right = 1+len[root->right].first + len[root->right].second;
            len[root] = {left, right};
        } else if(root->left) {
            treeLen(root->left, len);
            int left = 1+len[root->left].first + len[root->left].second;
            len[root] = {left, 0};
        } else {
            treeLen(root->right, len);
            int right = 1 + len[root->right].first + len[root->right].second;
            len[root] = {0, right};
        }
    }
    int kthSmallestHelper(TreeNode* root, int k, int cur, unordered_map<TreeNode*, pair<int, int> > &len) {
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
    }
    int kthSmallest(TreeNode* root, int k) {
        unordered_map<TreeNode*, pair<int, int> > len;
        treeLen(root, len);
        for(auto it:len) {
            cout<<it.first->val<<" "<<it.second.first<<" "<<it.second.second<<endl;
        }
        return kthSmallestHelper(root, k, 0, len);
    }
};
