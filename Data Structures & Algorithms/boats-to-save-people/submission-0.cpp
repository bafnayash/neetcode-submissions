class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end());
        int start = 0, end = n-1;
        int ans = 0;
        while(start <= end) {
            if(people[start] + people[end] <= limit) {
                ans++;
                start++;
                end--;
            } else {
                ans++;
                end--;
            }
        }
        //if(start == end) 
       //     ans++;
        return ans;
    }
};