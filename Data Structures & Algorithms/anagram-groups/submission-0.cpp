class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<int> > charComposition(n, vector<int> (26,0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < strs[i].size(); j++)
            charComposition[i][strs[i][j]-'a']++;
        }
        map<string, vector<int> > anagrams;
        for(int i = 0; i<n; i++) {
            string temp = "";
            for(int j = 0; j < 26; j++) {
                temp += charComposition[i][j];
            }
            anagrams[temp].push_back(i);
        }
        vector<vector<string> > ans;
        for(auto it:anagrams) {
            vector<string> tempAns;
            for(int i = 0; i < it.second.size(); i++) {
                tempAns.push_back(strs[it.second[i]]);
            }
            ans.push_back(tempAns);
        }
        return ans;
    }
};
