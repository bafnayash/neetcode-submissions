class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < 26; i++) {
            int start = 0, end = 0, tempK = k;
            while(start <= end && end < n) {
                if(s[end] - 'A' == i) {
                    end++;
                } else if(tempK > 0) {
                    tempK--;
                    end++;
                } else {
                    while(start < end && s[start]-'A' == i) {
                        start++;
                    }
                    start++;
                    end++;
                }
                ans = max(ans, end-start);
            }
        }
        //unordered_map<char, vector<int> > pos;
        /*for(int i = 0; i < n; i++) {
            //pos[s[i]].push_back(i);
            int tempK = k, j = i;
            while(j < n && (tempK > 0 || s[j] == s[i])) {
                if(s[j] == s[i]) {
                    j++;
                } else {
                    tempK--;
                    j++;
                }
            }    
            ans = max(ans, j-i);
        }
        /*for(auto it:pos) {
            int i = 1, tempK = k;
            while(i < it.second.size()) {
                if(it.second[i]-it.second[i-1] - 1 > tempK) {
                    ans = max(ans, 1+tempK);
                } else if(it.second[i]-it.second[i-1] - 1 > tempK)
            }
        }
        */
        return ans;
    }
};
