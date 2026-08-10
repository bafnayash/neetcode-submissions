class Solution {
public:
    struct TrieNode {
        unordered_map<char, TrieNode*> next;
        bool eof;
    };
    TrieNode* trie;
    int earlyStop = INT_MAX;
    string w;
    bool addWords(string cur, set<string> vis, int i, int j, vector<vector<char> > & board) {
        int n = board.size();
        int m = board[0].size();
        string temp = to_string(i) + "_" + to_string(j);
        if(i < 0 || j < 0 || i >= n || j >= m || vis.contains(temp)) {
            return false;
        }
        cur.push_back(board[i][j]);
        //cout<<i<<" "<<j<<" "<<cur<<endl;
        vis.insert(temp); 
        //insert(cur);  
        int curLen = cur.size(); 
        if(cur == w) {
            return true;
        }
        if(cur.size() >= earlyStop || (curLen > 0 && cur[curLen-1] != w[curLen-1])) {
            //cout<<cur<<" ";
            return false;
        }
        
        bool ans = addWords(cur, vis, i+1, j, board);
        ans |= addWords(cur, vis, i, j+1, board);
        ans |= addWords(cur, vis, i-1, j, board);
        ans |= addWords(cur, vis, i, j-1, board);
        return ans;
    }
    void insert(string word) {
        int n = word.size();
        int i = 0;
        TrieNode* cur = trie;
        while(i < n) {
            if(cur && !cur->next.contains(word[i]-'a')) {
                //cout<<word[i]<<" ";
                TrieNode * temp = new TrieNode();
                cur->next[word[i]-'a'] = temp;
            } 
            //cout<<word[i]<<" ";
            if(cur->next.empty())
            return;
            cur = cur->next[word[i]-'a'];
            i++;
        }
        cur->eof = true;
    }
    bool search(string word) {
        int n = word.size();
        //return false;
        TrieNode* cur = trie;
        int i = 0;
        if(cur == nullptr || cur->next.empty())
            return false;
        while(i < n) {
            //cout<<i<<" ";
            if(!cur->next.contains(word[i]-'a')) {
                //cout<<"Wow";
                return false;
            }
            if(cur->next.empty())
            return false;
            cur = cur->next[word[i]-'a'];
            i++;
        }
        return cur->eof;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int len = word.size();
        earlyStop = len;
        if(len == 0 || board.size() == 0) {
            return false;
        }
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < len; i++) {
            word[i] = toupper(word[i]);
        }
        w = word;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                board[i][j] = toupper(board[i][j]);
            }
        }
        trie = new TrieNode();
        set<string> vis;
        //for(int i = 0; i < )
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(addWords("", vis, i, j, board)) {
                    return true;
                }
            }
            //cout<<endl<<endl;
        }
        return false;
        return search(word);
    }
};
