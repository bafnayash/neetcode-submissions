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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) {
            return true;
        }
        if(!p || !q || p->val != q->val) {
            return false;
        }
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && subRoot)
            return false;
        TreeNode * cur = root;
        bool centre = isSameTree(cur, subRoot);
        if(centre)
            return centre;
        cur = root;
        //cout<<"L: "<<root->left<<endl;
        bool left = isSubtree(cur->left, subRoot);
        if(left)
            return left;
        cur = root;
        //cout<<"R: "<<root->right->val<<endl;
        bool right = isSubtree(cur->right, subRoot);
        return right;
    }
};
