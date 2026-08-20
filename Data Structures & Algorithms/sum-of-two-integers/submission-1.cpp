class Solution {
public:
    int getSum(int a, int b) {
        int ans = 0;
        for(int i = 0; i < 32; i++) {
            int bit1 = 1 << i & a;
            int bit2 = 1 << i & b;
            if(bit1 && bit2) {
                ans |= 1 << (i+1);
            } else if(bit1 || bit2) {
                if(ans & (1 << i)) {
                    ans = ans ^ (1 << i);
                    ans |= 1 << (i+1);
                } else {
                    ans |= 1 << i;
                }
            } 
        }
        return ans;
    }
};
