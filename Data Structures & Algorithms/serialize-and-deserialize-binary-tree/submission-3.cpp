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
class Codec {
public:
    //int mx = INT_MIN;
    void dfs(TreeNode* root, string & ans) {
        if(!root) {
            return;
        }
        if(!root->left && !root->right) {
            ans += to_string(root->val) + "#NULL#NULL,";
            return;
        } else if(root->left && root->right) {
            ans += to_string(root->val) + "#" + to_string(root->left->val) + "#" + to_string(root->right->val) + ",";
            dfs(root->left, ans);
            dfs(root->right, ans);
        } else if(root->left) {
            ans += to_string(root->val) + "#" + to_string(root->left->val) + "#NULL,";
            dfs(root->left, ans);
        } else {
            ans += to_string(root->val) + "#NULL#" + to_string(root->right->val) + ",";
            dfs(root->right, ans);
        }
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        dfs(root, ans);
        //cout<<ans<<"\n";
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n = data.size();
        int i = 0;
        if(n==0) {
            return nullptr;
        }
        //vector<int> tree;
        unordered_map<TreeNode*, int> pos;
        unordered_map<int,TreeNode*> reversePos;
        TreeNode* root = nullptr;
        while(i < n) {
            string rootVal = "";
            while(i < n && data[i] != '#') {
                rootVal+=data[i];
                i++;
            }
            i++;
            string leftVal = "";
            while(i < n && data[i] != '#') {
                leftVal+=data[i];
                i++;
            }
            i++;
            string rightVal = "";
            while(i < n && data[i] != ',') {
                rightVal+=data[i];
                i++;
            }
            TreeNode*left = nullptr;
            if(leftVal != "NULL") {
                int v = stoi(leftVal);
                left = new TreeNode(v);
                reversePos[v] = left;
            }
            TreeNode* right = nullptr;
            if(rightVal != "NULL") {
                int v = stoi(rightVal);
                right = new TreeNode(v);
                reversePos[v] = right;
            }
            TreeNode* temp = nullptr;
            int rv = stoi(rootVal);
            if(reversePos.contains(rv)) {
                temp = reversePos[rv];
            } else {
                temp = new TreeNode(rv);
                reversePos[rv] = temp;
            }
            temp->left = left;
            temp->right = right;
            if(!root) {
                root = temp;
            }
            i++;
        }
        return root;
    }
    /*void dfs(TreeNode* root, unordered_map<TreeNode*,int> & mp) {
        if(!root) {
            return;
        }
        if(!root->left && !root->right) {
            return;
        } else if(root->left && root->right) {
            mp[root->left] = 2*mp[root]+1;
            mp[root->right] = 2*mp[root]+2;
            //mx = max(mp[root->left], mx);
            //mx = max(mp[root->right], mx);
            dfs(root->left, mp);
            dfs(root->right, mp);
        } else if(root->left) {
            mp[root->left] = 2*mp[root]+1;
            //mx = max(mp[root->left], mx);
            dfs(root->left, mp);
        } else {
            mp[root->right] = 2*mp[root]+2;
            //mx = max(mp[root->right], mx);
            dfs(root->right, mp);
        }
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        queue<TreeNode*> q;
        int level = 0;
        q.push(root);
        while(!q.empty()) {
            ans += to_string(level)+"#";
            int size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if(temp) {
                    ans += to_string(temp->val)+",";
                    q.push(temp->left);
                    q.push(temp->right);
                } else {
                    ans += "NULL,";
                }
            }
            level++;            
        }
        unordered_map<TreeNode*,int> mp;
        if(!root)
            return "";
        mp[root] = 0;
        dfs(root, mp);
        //cout<<mx<<" ";
        if(mx == INT_MIN) {
            mx = 1;
        }
        vector<int> tree(mx+1, INT_MIN);
        for(auto it:mp) {
            ans += to_string(it.second) + "#" + to_string(it.first->val) + ",";
            //tree[it.second] = it.first->val;
        }
        for(int i = 0; i <= mx; i++) {
            //cout<<tree[i]<<" ";
            if(tree[i] != INT_MIN) {
                ans += to_string(tree[i]) + ",";
            } else {
                ans += "NULL,";
            }            
        }
        cout<<ans<<"\n";
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n = data.size();
        int i = 0;
        if(n==0) {
            return nullptr;
        }
        //vector<int> tree;
        unordered_map<TreeNode*, int> pos;
        unordered_map<int,TreeNode*> reversePos;
        while(i < n) {
            string elePos = "";
            while(i < n && data[i] != '#') {
                elePos+=data[i];
                i++;
            }
            i++;
            string value = "";
            while(i < n && data[i] != ',') {
                value+=data[i];
                i++;
            }
            TreeNode* temp = new TreeNode(stoi(value));
            pos[temp] = stoi(elePos);
            reversePos[stoi(elePos)] = temp;
            int cur = INT_MIN;
            if(level != "NULL") {
                cur = stoi(level);
            }
            tree.push_back(cur);
            //cout<<tree[tree.size()-1]<<" ";
            i++;
        }
        TreeNode* root = reversePos[0];
        //int size = tree.size();
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            //cout<<cur->val<<" ";
            int j = pos[cur];
            if(reversePos.contains(2*j+1)) {
                cur->left = reversePos[2*j+1];
                //pos[cur->left] = 2*j+1;
                q.push(cur->left);
            }
            if(reversePos.contains(2*j+2)) {
                cur->right = reversePos[2*j+2];
                //pos[cur->right] = 2*j+2;
                q.push(cur->right);
            }
        }
        return root;
    }*/
};
