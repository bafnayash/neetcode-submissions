class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int st = 0, en = 0;
        stack<int> ele;
        vector<int> preMax(n+1, 0);
        vector<int> sufMax(n+1, 0);
        preMax[0] = height[0];
        for(int i = 1; i < n; i++) {
            preMax[i] = max(preMax[i-1], height[i]);
        }
        for(int i = n-1; i >= 0; i--) {
            sufMax[i] = max(sufMax[i+1], height[i]);
        } 
        for(int i = 1; i < n; i++) {
            ans += max(0, min(preMax[i-1], sufMax[i+1]) - height[i]);
        }
        /*while(en+1 < n) {
            int prev = height[en];
            while(en < n-1 && prev <= height[en+1]) {
                //st++;
                en++;
                prev = height[en];
            }
            while(en < n-1 && height[en] >= height[en+1]) {
                ele.push(en);
                cout<<en<<" ";
                en++;
            }
            cout<<endl;
            while(en < n-1 && height[en] == height[en+1]) {
                en++;
            }
            int prevL = 0, prevR = 0;
            while(!ele.empty() && en+1 < n) {
                int cur = ele.top();
                ele.pop();
                cout<<"WOW "<<cur<<" "<<en<<endl;
                ans += (en+1-cur-1)*min(height[cur]-prevL, height[en+1]-prevR);
                prevL = height[cur];
                prevR = height[en+1];
                en++;
            }
        }*/
        return ans;
    }
};
