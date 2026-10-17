class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int maxDist = 0;
        int n = trips.size();
        for(int i = 0; i < n; i++) {
            maxDist = max(maxDist, trips[i][2]);
        }
        vector<int> pos(maxDist+1, 0);
        for(int i = 0; i < n; i++) {
            pos[trips[i][1]] += trips[i][0];
            pos[trips[i][2]] -= trips[i][0];
        }
        int sum = 0;
        for(int i = 0; i <= maxDist; i++) {
            sum += pos[i];
            if(sum > capacity) {
                return false;
            } 
        }
        return true;
    }
};