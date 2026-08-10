class Solution {
public:
    struct TrieNode {
        unordered_map<char, TrieNode*> next;
        bool eof;
    };
    TrieNode* trie;
    set<string> globalVis;
    int earlyStop = INT_MAX;
    /*void addWords(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                string temp = "";
                temp.push_back(board[i][j]);
                insert(temp);
                for (int k = 1; j+k < m; k++) {
                    temp.push_back(board[i][j+k]);
                    insert(temp);
                    cout<<temp<<endl;
                }
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                string temp = "";
                temp.push_back(board[j][i]);
                insert(temp);
                for (int k = 1; j+k < n; k++) {
                    temp.push_back(board[j+k][i]);
                    insert(temp);
                    cout<<temp<<endl;
                }
            }
        }
    }*/
    void addWords(string cur, set<string> vis, int i, int j, vector<vector<char> > & board) {
        int n = board.size();
        int m = board[0].size();
        string temp = to_string(i) + "_" + to_string(j);
        if(i < 0 || j < 0 || i >= n || j >= m || vis.contains(temp)) {
            return;
        }
        cur.push_back(board[i][j]);
        //cout<<i<<" "<<j<<" "<<cur<<endl;
        vis.insert(temp); 
        insert(cur);   
        if(cur.size() >= earlyStop)
            return;
        if(i+1 < n) {
            //string rev(cur.rbegin(), cur.rend());
            //insert(rev);
            addWords(cur, vis, i+1, j, board);
            //cur.pop_back();
            //vis.erase(temp);
            /*set<string> newVis;
            newVis.insert(temp);
            string t = "";
            t.push_back(board[i][j]);
            addWords(t, newVis, i+1, j, board);*/
        }
        if(j+1 < m) {
            //cur.push_back(board[i][j]);
            //insert(cur);
            //cout<<i<<" "<<j<<" "<<cur<<endl;
            //string rev(cur.rbegin(), cur.rend());
            //insert(rev);
            //vis.insert(temp);
            //cout<<i<<" "<<j<<" "<<cur<<endl;
            addWords(cur, vis, i, j+1, board);
            //cur.pop_back();
            //vis.erase(temp);
            /*set<string> newVis;
            newVis.insert(temp);
            string t = "";
            t.push_back(board[i][j]);
            addWords(t, newVis, i, j+1, board);*/
        }
        if(i >= 1) {
            //cur.push_back(board[i][j]);
            //vis.insert(temp);
            //cout<<i<<" "<<j<<" "<<cur<<endl;
            //insert(cur);
            //string rev(cur.rbegin(), cur.rend());
            //insert(rev);
            addWords(cur, vis, i-1, j, board);
            //cur.pop_back();
            //vis.erase(temp);
            //set<string> newVis;
            //addWords("", newVis, i-1, j, board);
        }
        if(j >= 1) {
            //cur.push_back(board[i][j]);
            //vis.insert(temp);
            //cout<<i<<" "<<j<<" "<<cur<<endl;
            //insert(cur);
            //string rev(cur.rbegin(), cur.rend());
            //insert(rev);
            addWords(cur, vis, i, j-1, board);
            //cur.pop_back();
            //vis.erase(temp);
            //set<string> newVis;
            //addWords("", newVis, i, j-1, board);
        }
        //globalVis.insert(temp);
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
                addWords("", vis, i, j, board);
            }
            //cout<<endl<<endl;
        }
        /*vector<vector<char>> temp(n, vector<char> (m, '.'));
        for(int i = 0; i < n; i++) {
            for(int j = m-1; j >= 0; j--) {
                temp[i][m-1-j] = board[i][j];
            }
        }
        addWords("", vis, 0, 0, temp);
        //vector<vector<char>> temp(n, vector<char> (m, '.'));
        for(int i = n-1; i >= 0; i--) {
            for(int j = 0; j < m; j++) {
                temp[n-1-i][j] = board[n-1-i][j];
            }
        }
        addWords("", vis, 0, 0, temp);
        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j >= 0; j--) {
                temp[n-1-i][m-1-j] = board[n-1-i][m-1-j];
            }
        }
        addWords("", vis, 0, 0, temp);*/
        return search(word);
    }
};
