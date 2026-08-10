/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<int, set<int> > v;
        queue<Node*> q;
        if(node == nullptr)
            return node;
        q.push(node);
        while(!q.empty()) {
            Node* front = q.front();
            q.pop();
            //vector<Node*> n;
            /*for(auto i:front->neighbors) {
                Node* temp = new Node(i->val, i->neighbors);
                n.push_back(temp);
            }*/
            //v[front->val] = n;
            //cout<<"Front: "<<front->val<<" ";
            for(auto it:front->neighbors) {
                if(!v.contains(it->val)) {
                    q.push(it);
                    //cout<<it->val<<" ";  
                }
                v[front->val].insert(it->val);
            }
            front = nullptr;
            //cout<<endl;
        }
        //Node* ans = nullptr;
        //cout<<"Size: "<<v.size()<<endl;
        if(v.size() == 0) {
            return new Node();
        }
        //vector<Node*> wow = {nullptr};
        //if(v.size() == 1)
        //    return new Node(1, wow);
        //Node* ans = new Node(v.begin()->first, v.begin()->second);
        map<int, Node*> nodeMap;
        for(auto it:v) {
            nodeMap[it.first] = new Node(it.first);
        }
        for(auto it:v) {
            vector<Node*> curMap = {};
            for(auto it2:it.second) {
                curMap.push_back(nodeMap[it2]);
            }
            nodeMap[it.first]->neighbors = curMap;
        }
        /*for(auto it:v) {
            cout<<it.first<<" LIST: ";
            Node* temp = new Node(it.first, it.second);
        }*/
        return nodeMap[1];
    }
};
