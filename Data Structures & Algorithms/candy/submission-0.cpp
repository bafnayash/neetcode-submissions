class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans = 0;
        int n = ratings.size();
        /*int i = 0;
        while(i < n) {
            cout<<i<<" "<<ans<<endl;
            int cur = ratings[i];
            int temp = i+1;
            bool equal = false;
            while(temp < n && ratings[temp] == cur) {
                temp++;
                equal = true;
            }
            if(equal) {
                ans += temp - i;
                if(temp == n)
                    break;
                i = temp - 1;
                cur = ratings[i];
                temp = i+1;
            }
            cout<<i<<" "<<ans<<endl;
            bool increasing = false;
            while(temp < n && ratings[temp] > cur) {
                cur = ratings[temp];
                temp++;
                increasing = true;
            }
            if(increasing) {
                ans += ((temp-1-i+1)*(temp-i+1))/2;
                if(equal) {
                    ans -= 1;
                }
                if(temp == n)
                    break;
                i = temp-1;
                cur = ratings[i];
                temp = i+1;
            }
            cout<<i<<" "<<ans<<endl;
            bool decreasing = false;
            while(temp < n && ratings[temp] < cur) {
                cur = ratings[temp];
                temp++;
                decreasing = true;
            }
            if(decreasing) {
                if(increasing) {
                    i = i+1;
                }
                ans += ((temp-1-i+1)*(temp-i+1))/2;
                if(equal && !increasing) {
                    ans -= 1;
                }
                if(temp == n)
                    break;
                i = temp-1;
            }
        }
        int prev = -1;
        cout<<ans;
        for(int i = 1; i < n; i++) {
            int cur = -1;
            if(ratings[i] == ratings[i-1]) {
                cur = 0;
            } else if(ratings[i] > ratings[i-1]) {
                cur = 1;
            } else {
                cur = 2;
            }
            if(prev != -1) {
                if((cur == 0 && prev != 0) || (prev == 2 && cur == 1)) {
                    ans -= 1;
                }
            } 
            prev = cur;
        }
        return ans;*/
        int prev = -1, cont = 0;
        int prevCont = 0;
        ans = n;
        //cout<<ans;
        for(int i = 1; i < n; i++) {
            int cur = -1;
            if(ratings[i] == ratings[i-1]) {
                cur = 0;
            } else if(ratings[i] > ratings[i-1]) {
                cur = 1;
            } else {
                cur = 2;
            }
            if(prev != cur) {
                prevCont = cont;
            }
            if(prev == 1 && cur == 2) {
                int temp = i+1;
                int cur = ratings[i];
                int tempCount = 1;
                while(temp < n && ratings[temp] < cur) {
                    tempCount++;
                    cur = ratings[temp];
                    temp++;
                }
                cout<<"NEW "<<prevCont<<" "<<tempCount<<endl;
                ans += max(0, tempCount - prevCont);
                cont = 0;
            } else if(prev == cur && cur) {
                cont++;
            } else if(cur) {
                cont = 1;
            } else {
                cont = 0;
            }
            ans += cont; 
            prev = cur;
            cout<<ans-(n-1-i-1+1)<<" ";
        }
        return ans;
    }
};