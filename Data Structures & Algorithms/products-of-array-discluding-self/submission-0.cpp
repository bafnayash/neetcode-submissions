class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefixProd(n+1,1), suffixProd(n+2,1);
        for(int i = 0; i <n;i++) {
            prefixProd[i+1] = prefixProd[i]*nums[i];
        }
        for(int i = n-1; i>=0;i--) {
            suffixProd[i+1] = suffixProd[i+2]*nums[i];
        }
        vector<int> prod;
        for(int i = 0; i <n;i++) {
            prod.push_back(prefixProd[i]*suffixProd[i+2]);
        }
        return prod;
    }
};
