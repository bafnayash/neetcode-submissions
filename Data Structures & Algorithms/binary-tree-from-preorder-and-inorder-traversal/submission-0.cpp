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
    unordered_map<int, int> posIn, posPre;
    TreeNode* buildTreeHelper(int pLow, int pHigh, int iLow, int iHigh, vector<int>& preorder, vector<int>& inorder) {
        int n = pHigh-pLow+1;
        if(n==0)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[pLow]);
        int mid = posIn[preorder[pLow]];
        int size = mid-1-iLow+1;
        root->left = buildTreeHelper(pLow+1,pLow+1+size-1,iLow, mid-1, preorder, inorder);
        root->right = buildTreeHelper(pLow+size+1,pHigh,mid+1, iHigh, preorder, inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i = 0; i < n; i++) {
            posIn[inorder[i]] = i;
            posPre[preorder[i]] = i;
        }
        return buildTreeHelper(0, n-1, 0, n-1, preorder, inorder);
    }
};
