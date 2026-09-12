class Solution {
public:
    int update(int n) {
        int ans = 0;
        while(n > 0) {
            ans += (n%10)*(n%10);
            n /= 10;
        }
        return ans;
    }
    bool isHappy(int n) {
        set<int> done;
        while(!done.contains(n)) {
            done.insert(n);
            n = update(n);
            if(n == 1) {
                return true;
            }
            cout<<n<<endl;
        } 
        return false;
    }
};
