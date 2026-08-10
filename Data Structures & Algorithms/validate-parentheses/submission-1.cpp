class Solution {
public:
    bool isValid(string s) {
        int n = s.size(), i = 0;
        stack<char> valid;
        while(i<n) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[' ) {
                valid.push(s[i]);
            } else if(valid.size() == 0) {
                return false;
            } else {
                char lastChar = valid.top();
                if((lastChar == '(' && s[i] == ')') || (lastChar == '[' && s[i] == ']') || (lastChar == '{' && s[i] == '}')) {
                    valid.pop();    
                } else {
                    return false;
                }
            }
            i++;
        }
        if(valid.size() == 0)
            return true;
        return false;
    }
};
