class Solution {
public:
    bool isAlphaNumeric(char s) {
        if((s-'a' >= 0 && s-'a' <= 25) || (s-'A' >= 0 && s-'A' <= 25) || (s-'0' >= 0 && s-'0' <= 9))
            return true;
        return false;
    }
    bool isPalindrome(string s) {
        int n = s.size();
        string alpha = "";
        for(int i = 0; i < n; i++) {
            if(isAlphaNumeric(s[i])) {
                alpha += tolower(s[i]);
            }
        }
        cout<<alpha;
        int i = 0, j = alpha.size()-1;
        while(i < j) {
            if(alpha[i] != alpha[j]) {
                //cout<<i<<" "<<j;
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
