class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for(uint32_t i = 0; i <= 31; i++) {
            uint32_t bit = (1 << i) & n;
            cout<<bit<<" ";
            ans |= (1 << (31-i))*(bit > 0);
        }
        return ans;
    }
};
