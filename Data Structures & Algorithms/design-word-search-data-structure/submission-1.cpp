class WordDictionary {
public:
    struct TrieNode {
        bool eof;
        unordered_map<char, TrieNode*> children;
        TrieNode() {
            this->eof = false;
        }
    };
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        int n = word.size();
        int i = 0;
        while(i < n) {
            if(!cur->children.contains(word[i])) {
                cur->children[word[i]] = new TrieNode();
            }
            cur = cur->children[word[i]];
            i++;
        }
        cur->eof = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        int i = 0;
        int n = word.size();
        while(i < n) {
            if(word[i] == '.') {
                bool ans = false;
                string temp = word;
                for(auto it:cur->children) {
                    temp[i] = it.first;
                    ans |= search(temp);
                }
                if(ans)
                    return true;
                else 
                    return false;
            } else if(!cur->children.contains(word[i])) {
                return false;
            }
            cur = cur->children[word[i]];
            i++;
        }
        return cur->eof;
    }
};
