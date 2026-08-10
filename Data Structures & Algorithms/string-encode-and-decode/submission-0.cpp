class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedStr = "";
        for(int i = 0; i < strs.size(); i++) {
            int size = strs[i].size();
            encodedStr += to_string(size) + "_" + strs[i];
        }
        return encodedStr;
    }

    vector<string> decode(string s) {
        int i = 0;
        vector<string> decodedStr;
        while(i < s.size()) {
            string lenStr = "";
            while(s[i] != '_') {
                lenStr += s[i];
                i++;
            }
            int len = stoi(lenStr);
            i++;
            string decodedElement = "";
            while(decodedElement.size() < len) {
                decodedElement += s[i];
                i++;
            }
            decodedStr.push_back(decodedElement);
        }
        return decodedStr;
    }
};
