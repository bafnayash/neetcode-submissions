class Solution {
public:
    static bool comp(pair<int,int> & p1, pair<int,int> & p2) {
        return p1.first > p2.first;
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int> > cars;
        for(int i = 0; i < n; i++) {
            cars.push_back({target-position[i], speed[i]});
        }
        sort(cars.begin(), cars.end(), comp);
        int ans = 0;
        int st = 1;
        stack<pair<int,int> > s;
        if(n == 1) {
            return 1;
        }
        s.push(cars[0]);
        while(st < n) {
            pair<int,int> cur = s.top();
            double timeToReachA = ((double)cur.first)/cur.second;
            double timeToReachB = ((double)cars[st].first)/cars[st].second;
            //cout<<timeToReachA<<" "<<timeToReachB<<endl;
            if(timeToReachA > timeToReachB) {
                s.push(cars[st]);
                st++;
            } else {
                s.pop();
                if(s.empty()) {
                    s.push(cars[st]);
                    st++;
                }
            }
        }
        return s.size();
    }
};
