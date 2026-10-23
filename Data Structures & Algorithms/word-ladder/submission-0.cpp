class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        int n = beginWord.size();
        int m = endWord.length();
        int size = wordList.size();
        set<string> word;
        for(int i = 0; i < size; i++) {
            word.insert(wordList[i]);
        }
        if(n != m || beginWord == endWord || !word.contains(endWord)) {
            return 0;
        }
        q.push(beginWord);
        set<string> vis;
        int ans = 1;
        vis.insert(beginWord);
        while(!q.empty()) {
            int curSize = q.size();
            for(int i = 0; i < curSize; i++) {
                string cur = q.front();
                q.pop();
                for(int j = 0; j < n; j++) {
                    for(int k = 0; k < 26; k++) {
                        string temp = cur;
                        temp[j] = (char)('a' + k);
                        if(temp == endWord) {
                            return ans+1;
                        }
                        if(temp != cur && word.contains(temp) && !vis.contains(temp)) {
                            q.push(temp);
                            vis.insert(temp);
                           // cout<<temp<<" "<<ans<<endl;
                        }
                    }
                }
            }
            ans++;
        }
        return 0;
    }
};
