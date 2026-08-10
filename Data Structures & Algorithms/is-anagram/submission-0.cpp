class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> charS, charT;
        int n = s.size(), m = t.size();
        for(int i=0;i<n;i++) {
            charS[s[i]]++;
        }
        for(int i=0;i<m;i++) {
            charT[t[i]]++;
        }
        if(charS.size() != charT.size())
            return false;
        for(auto it:charS) {
            if(it.second != charT[it.first])
                return false;
        }
        return true;
    }
};
