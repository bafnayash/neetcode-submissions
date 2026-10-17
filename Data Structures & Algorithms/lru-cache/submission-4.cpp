struct ListNode {
    int val;
    int key;
    ListNode* left;
    ListNode* right;
    ListNode(): val(0), key(0), left(nullptr), right(nullptr) {}
    ListNode(int x, int y): val(x), key(y), left(nullptr), right(nullptr) {}
    ListNode(int x, int y, ListNode* l, ListNode* r): val(x), key(y), left(l), right(r) {}
};
class LRUCache {
private:
    int cnt;
    int size;
    map<int, ListNode*> pos;
    ListNode* start;
    ListNode* end;
public:
    LRUCache(int capacity) {
        size = capacity;
        cnt = 0;
        start = nullptr;
        end = nullptr;
    }
    
    int get(int key) {
        if(!pos.contains(key)) {
            return -1;
        }
        ListNode* cur = pos[key];
        if(cnt == 1 || cur == end) {
            return cur->val;
        }
        if(cur->left != nullptr) {
            cur->left->right = cur->right;
        }
        if(cur->right != nullptr) {
            cur->right->left = cur->left;
            //cur->right = nullptr;
        }
        if(cur == start) {
            //cout<<cur->val<<" "<<start->val<<" START before \n";
            start = start->right;
          //  cout<<cur->val<<" "<<start->val<<" START after \n";
        }
        end->right = cur;
        cur->left = end;
        //cur->right = nullptr;
        end = end->right;
        //end->right = nullptr;
       // cout<<start->val<<" "<<end->val<<" GET "<<endl;
        return cur->val;
    }
    
    void put(int key, int value) {
        if(pos.contains(key)) {
            ListNode* cur = pos[key];
            cur->val = value;
            if(cnt == 1 || cur == end) {
                return;
            }    
            if(cur->left) {
                cur->left->right = cur->right;
            }
            if(cur->right) {
                cur->right->left = cur->left;
            }
            if(cur == start) {
                //cout<<cur->val<<" "<<start->val<<" START before \n";
                start = start->right;
                //cout<<cur->val<<" "<<start->val<<" START after \n";
            }
            end->right = cur;
            cur->left = end;
            //cur->right = nullptr;
            end = end->right;
            //end->right = nullptr;
            //cout<<start->val<<" "<<end->val<<" GET "<<endl;
            return;
        }
        if(cnt == size) {
            pos.erase(start->key);
            if(start == end) {
                start = nullptr;
                end = nullptr;
            } else {
                start = start->right;
                if(start)
                    start->left = nullptr;
            }
            cnt--;
        }
        if(start == end && start == nullptr) {
            ListNode* cur = new ListNode(value, key);
            start = cur;
            end = cur;
            pos[key] = cur;
            cnt++;
        } else {
            ListNode* cur = new ListNode(value, key, end, nullptr);
            end->right = cur;
            end = cur;
            pos[key] = cur;
            cnt++;
        }
        //cout<<start->val<<" "<<end->val<<endl;
    }
};
