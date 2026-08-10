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
    bool getParents(TreeNode* root, TreeNode* p, vector<TreeNode*>&par) {
        if(!root)
            return false;
        if(root == p) {
            par.push_back(root);
            return true;
        }
        bool left = getParents(root->left, p,par);
        if(left) {
            par.push_back(root);
        }
        bool right = getParents(root->right, p,par);
        if(right) {
            par.push_back(root);
        }
        return left || right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> parP, parQ;
        getParents(root, p, parP);
        getParents(root, q, parQ);
        unordered_map<TreeNode*, int> pos;
        for(int i = 0; i < parP.size(); i++) {
            pos[parP[i]] = i;
            //cout<<parP[i]->val<<" ";
        }
        //cout<<endl;
        int ansPos = 1e9;
        TreeNode* ans = nullptr;
        for(int i = 0; i < parQ.size(); i++) {
            //cout<<parQ[i]->val<<" ";
            if(pos.contains(parQ[i]) && ansPos > pos[parQ[i]]) {
                ans = parQ[i];
                ansPos = pos[parQ[i]];
            }
        }
        return ans;
    }
};
