class Solution {
public:
    int bsL(int l, int h, vector<int> & sum, int target, int right) {
        int n = sum.size();
        while(l < h) {
            int mid = l + (h-l+1)/2;
            if(right - sum[mid] >= target) {
                l = mid;
            } else {
                h = mid-1;
            }
        }
        return l+1;
    }
    int bsR(int l, int h, vector<int> & sum, int target, int left) {
        int n = sum.size();
        while(l < h) {
            int mid = l + (h-l)/2;
            if(sum[mid] - left >= target) {
                h = mid;
            } else {
                l = mid+1;
            }
        }
        return h;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n+1,0);
        sum[0] = nums[0];
        for(int i = 1; i < n; i++) {
            sum[i] = sum[i-1] + nums[i];
        }
        if(sum[n-1] < target) {
            return 0;
        }
        int st = 0, en = 0;
        int cur = 0;
        int ans = 1e7;
        while(st <= en && en < n) {
            cur = sum[en] - ((st > 0) ? sum[st-1] : 0);
            while(cur < target && en < n) {
                en++;
                cur = sum[en] - ((st > 0) ? sum[st-1] : 0);
            }
            if(en == n) {
                cur = sum[en-1] - ((st > 0) ? sum[st-1] : 0);
                while(cur >= target && st <= en) {
                    cout<<st<<" "<<en<<" "<<en-st<<" 1 \n";
                    ans = min(ans, en - st);
                    st++;
                    cur = sum[en-1] - ((st > 0) ? sum[st-1] : 0);
                }
            } else {
                cur = sum[en] - ((st > 0) ? sum[st-1] : 0);
                while(cur >= target && st <= en) {
                    cout<<st<<" "<<en<<" "<<en-st+1<<" 2 \n";
                    ans = min(ans, en - st + 1);
                    st++;
                    cur = sum[en] - ((st > 0) ? sum[st-1] : 0);
                }
                if(st == en) {
                    en++;
                }
            }
        }
        return ans;
        int left1 = bsL(0, n-1, sum, target, sum[n-1]);
        int subtract = (left1-1 >= 0) ? sum[left1-1] : 0;
        int right1 = bsR(left1, n-1, sum, target, subtract);
        int right2 = bsR(0, n-1, sum, target, 0);
        int left2 = bsL(0, n-1, sum, target, sum[right2]);
        //int subtract1 = (left-1 >= 0) ? sum[left-1] : 0;
        
        cout<<left1<<" "<<right1<<endl;
        cout<<left2<<" "<<right2<<endl;
        return min(right1-left1+1, right2-left2+1) ;
    }
};