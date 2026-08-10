class Solution {
public:
    struct TrieNode {
        bool eof;
        unordered_map<int, TrieNode*> next;
        TrieNode() {
            eof = false;
        }
    };
    TrieNode* trie;
    unsigned long earlyStop = 0;
    void insert(string word) {
        int n = word.size();
        int i = 0;
        TrieNode* cur = trie;
        while(i < n) {
            if(cur && !cur->next.contains(word[i]-'a')) {
                TrieNode * temp = new TrieNode();
                cur->next[word[i]-'a'] = temp;
            } 
            cur = cur->next[word[i]-'a'];
            i++;
        }
        cur->eof = true;
    }
    bool search(string word) {
        int n = word.size();
        TrieNode* cur = trie;
        int i = 0;
        while(i < n) {
            if(!cur || !cur->next.contains(word[i]-'a')) {
                return false;
            }
            cur = cur->next[word[i]-'a'];
            i++;
        }
        return cur->eof;
    }
    void addWords(string cur, int i, int j, vector<vector<char> > & board) {
        int n = board.size();
        int m = board[0].size();
        string temp = to_string(i) + "_" + to_string(j);
        if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] == '#') {
            return;
        }
        cur.push_back(board[i][j]);
        insert(cur);
        if(cur.size() >= earlyStop) {
            //cout<<cur<<" ";
            return;
        }
        char c = board[i][j];
        //cout<<cur<<endl;
        //vis.insert(temp);
        //cout<<endl<<board[i][j]<<" ";
        board[i][j] = '#';
        //cout<<board[i][j]<<" ";
        int curLen = cur.size(); 
        addWords(cur, i+1, j, board);
        addWords(cur, i, j+1, board);
        addWords(cur, i-1, j, board);
        addWords(cur, i, j-1, board);
        board[i][j] = c;
        //cout<<board[i][j];
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int size = words.size();
        if(size == 0 || board.size() == 0) {
            return {};
        }
        for(int i = 0; i < size; i++) {
            earlyStop = max(earlyStop, words[i].size());
        }
        //cout<<earlyStop<<" ";
        int n = board.size();
        int m = board[0].size();
        trie = new TrieNode();
        unordered_set<string> vis;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                addWords("", i, j, board);
            }
            //cout<<endl<<endl;
        }
        vector<string> ans;
        for(int i = 0; i < size; i++) {
            bool searchRes = search(words[i]);
            //cout<<words[i]<<" ANS: "<<searchRes<<endl;
            if(searchRes) {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};
