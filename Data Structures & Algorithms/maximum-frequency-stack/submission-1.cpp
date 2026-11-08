class FreqStack {
public:
    struct Node {
        int val;
        Node* left;
        Node* right;
        Node(int v): val(v), left(nullptr), right(nullptr) {};
        Node(int v, Node* l, Node* r): val(v), left(l), right(r) {};
    };
    //Node* head;
    //map<int, vector<Node*> > pos;
    map<int, int> freq;
    priority_queue<tuple<int, int, int> > pq;
    int timestamp;
    FreqStack() {
        //head = new Node(0);
        timestamp = 0;
    }
    
    void push(int val) {
        // Node* temp = new Node(val, head, nullptr);
        // head->right = temp;
        // head = head->right;
        // pos[val].push_back(temp);
        freq[val]++;
        timestamp++;
        pq.push({freq[val], timestamp, val});
    }
    
    int pop() {
        auto [a, b, val] = pq.top();
        pq.pop();
        freq[val]--;
        // int sz = pos[val].size();
        // auto it = pos[val][sz-1];
        // pos[val].pop_back();
        // Node* l = nullptr;
        // Node* r = nullptr;
        // if(it->left) {
        //     l = it->left;
        // }
        // if(it->right) {
        //     r = it->left;
        // }
        // if(l) {
        //     l->right = r;
        // }
        // if(r) {
        //     r->left = l;
        // }
        // if(it == head) {
        //     head = l;
        // }
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */