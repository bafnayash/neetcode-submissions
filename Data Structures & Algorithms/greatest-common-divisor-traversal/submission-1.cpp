class DSU {
    private:
        int n;
        vector<int> par;
        vector<int> size;
    public:
        DSU(int n, int mx) {
            this->n = n;
            par.clear();
            par.resize(mx+1);
            size.clear();
            size.resize(mx+1);
            for(int i = 0; i <= mx; i++) {
                size[i] = 1;
                par[i] = i;
            }
        }
        int getParent(int num) {
            while(num != par[num]) {
                num = par[num];
            }
            return num;
        }
        bool merge(int num1, int num2) {
            int par1 = getParent(num1);
            int par2 = getParent(num2);
            if(size[par1] == n || size[par2] == n) {
                return true;
            }
            if(par1 == par2) {
                return false;
            }
            if(size[par1] >= size[par2]) {
                par[par2] = par1;
                size[par1] += size[par2];
            } else {
                par[par1] = par2;
                size[par2] += size[par1];
            }
            if(size[par1] == n || size[par2] == n) {
                return true;
            }
            return false;
        }
};
class Solution {
public:
    void checkPrime(int mx, vector<bool> & isPrime) {
        int limit = mx;
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i = 2; i*i <= mx; i++) {
            for(int j = i*i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        if(n == 1) {
            return true;
        }
        set<int> nu;
        for(int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            nu.insert(nums[i]);
        } 
        vector<bool> isPrime(mx+1, true);
        checkPrime(mx, isPrime);
        bool ans = false;
        auto dsu = DSU(nu.size(), mx);
        for(int i = 2; i <= mx; i++) {
            if(isPrime[i]) {
                int fi = -1;
                for(int j = 0; j < n; j++) {
                    if(nums[j]%i == 0 && fi != -1) {
                        //cout<<fi<<" "<<nums[j]<<endl;
                        ans |= dsu.merge(fi, nums[j]);
                    } else if(nums[j]%i == 0) {
                        fi = nums[j];
                    }
                    if(ans) {
                        return ans;
                    }
                }
            }
        }
        return false;
    }
};