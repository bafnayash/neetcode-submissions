class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i = 0, j = n-1;
        int ans = 0;
        while(i<j) {
            ans = max(ans, (j-i)*(min(heights[i], heights[j])));
            if(heights[i] <= heights[j]) {
                i++;
            } else {
                j--;
            }
        }
        return ans;
    }
};
