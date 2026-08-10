class Solution {
public:
    set<string> words;
    map<string, bool> dp;
    bool wordBreakHelper(string s) {
        //cout<<s<<" ";
        if(words.contains(s)) {
            return true;
        }
        if(dp.contains(s)) {
            return dp[s];
        }
        int i = 0, n = s.size();
        string cur = "";
        bool ans = false;
        while(i < n) {
            if(words.contains(cur)) {
                string temp = s.substr(cur.size());
                ans |= wordBreakHelper(temp);
                if(ans)
                    return ans;
                dp[temp] = ans;
            }
            cur += s[i];
            i++;
        }
        return ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        int m = wordDict.size();
        for(int i = 0; i < m; i++) {
            words.insert(wordDict[i]);
        }
        return wordBreakHelper(s);
    }
};
