class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        int minLen = 1e9;
        string ans = "";
        unordered_map<char, int> count;
        for(int i = 0; i < m; i++) {
            count[t[i]]++;
        }
        for(int i = 0; i < n; i++) {
            int end = i;
            unordered_map<char, int> temp = count;
            bool flag = false;
            while(end < n) {
                if(temp.contains(s[end])) {
                    temp[s[end]]--;
                    if(temp[s[end]] == 0) {
                        temp.erase(s[end]);
                    }
                    /*for(auto it:temp) {
                        cout<<i<<" "<<end<<" "<<it.first<<" "<<it.second<<endl;
                    }*/
                }
                if(temp.size() == 0) {
                    flag = true;
                    //cout<<end<<" BREAK\n";
                    break;
                }
                end++;
            }
            if(end-i+1 < minLen && flag) {
                minLen = end-i+1;
                ans = s.substr(i, minLen);
            }
        }
        return ans;
    }
};
