class Solution {
public:
    int finalAns = 1e7;
    map<string, int> dp;
    int minExtraCharHelper(string s, set<string> dict) {
        int n = s.size();
        if(n == 0) {
            return 0;
        }
        if(dp.contains(s)) {
            return dp[s];
        }
        int i = 0;
        string cur = "";
        int ans = 1e7;
        while(i < n) {
            if(i < n && cur != "") {
                cur += s[i];
                i++;
            }
            while(!dict.contains(cur) && i < n) {
                cur += s[i];
                i++;
            }
            if(dict.contains(cur)) {
                ans = min(minExtraCharHelper(s.substr(i), dict), ans);
                //cout<<cur<<endl<<s.substr(i)<<" "<<ans<<endl;;
                //finalAns = min(ans, finalAns);
            } else {
                int op1 = 1 + minExtraCharHelper(s.substr(1), dict);
                int op2 = s.size();
                ans = min(min(op1, op2), ans);
                //cout<<"WOW "<<s<<" "<<ans<<endl;
            }
            //cout<<cur<<" "<<s<<" "<<ans<<" YES ";
        }
        //finalAns = min(ans, finalAns);
        dp[s] = ans;
        //cout<<s<<" "<<dp[s]<<endl;
        return ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        set<string> dict;
        int n = s.size();
        int m = dictionary.size();
        for(int j = 0; j < m; j++) {
            dict.insert(dictionary[j]);
        }
        return minExtraCharHelper(s, dict);
        return finalAns;
    }
};