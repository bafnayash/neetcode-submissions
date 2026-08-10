class PrefixTree {
public:
    struct TrieNode {
        bool eof;
        unordered_map<int, TrieNode*> next;
        TrieNode() {
            this->eof = false;
            next.clear();
        }
    };
    TrieNode* trie;
    PrefixTree() {
        trie = new TrieNode();
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
    
    bool startsWith(string prefix) {
        string word = prefix;
        //return false;
        int n = word.size();
        TrieNode* cur = trie;
        if(cur == nullptr || cur->next.empty())
        return false;
        int i = 0;
        while(i < n) {
            if(!cur->next.contains(word[i]-'a')) {
                return false;
            }
            if(cur->next.empty())
            return false;
            cur = cur->next[word[i]-'a'];
            i++;
        }
        return true;
    }
};
