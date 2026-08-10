class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        int start = 0, end = 0;
        unordered_map<char, int> subSequence;
        while(start <= end && end<n) {
            while(start<end && subSequence[s[end]]>0) {
                //cout<<s[end]<<" "<<subSequence[s[end]]<<" "<<end<<endl;
                subSequence[s[start]]--;
                start++;
            }
            //cout<<start<<" "<<end<<endl;
            subSequence[s[end]]++;
            ans = max(ans, end-start+1);
            end++;
        }
        return ans;
    }
};
