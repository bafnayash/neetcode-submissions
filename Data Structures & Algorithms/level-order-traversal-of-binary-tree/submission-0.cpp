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
    vector<vector<int>> levelOrder(TreeNode* root) {
        int level = 0;
        if(!root)
            return {};
        queue<pair<TreeNode*,int> > traverse;
        traverse.push({root, level});
        vector<vector<int> > ans;
        while(!traverse.empty()) {
            vector<int> temp;
            while(traverse.front().second == level) {
                TreeNode* front = traverse.front().first;
                traverse.pop();
                if(front->left) {
                    traverse.push({front->left,level+1});
                }
                if(front->right) {
                    traverse.push({front->right,level+1});
                }
                temp.push_back(front->val);
            }
            ans.push_back(temp);
            level++;
        }
        return ans;
    }
};
