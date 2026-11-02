class Solution {
public:
    static bool comp(vector<int> &v1, vector<int> &v2) {
        return v1[0] < v2[0];
    }
    struct Room {
        int roomNo;
        int timeAvailable;
        Room(int r, int t): roomNo(r), timeAvailable(t) {};
        bool operator< (const Room & r1) const {
            //if(timeAvailable == r1.timeAvailable) {
                return roomNo > r1.roomNo;
          //  }    
            //return timeAvailable > r1.timeAvailable;
        }
    };
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), comp);
        priority_queue<Room> q;
        for(int i = 0; i < n; i++) {
            auto r = Room(i, 0);
            q.push(r);
        }
        int mx = 0, ans = -1;
        map<int, int> meetingCount;
        int m = meetings.size();
        for(int i = 0; i < m; i++) {
            vector<Room> temp;
            auto next = q.top();
            //q.pop();
            int mi = next.timeAvailable, room = next.roomNo;
            while(!q.empty() && next.timeAvailable > meetings[i][0]) {
                temp.push_back(next);
                q.pop();
                next = q.top();
                if(mi > next.timeAvailable) {
                    mi = next.timeAvailable;
                    room = next.roomNo;
                }
            }
            if(!q.empty()) {
                temp.push_back(next);
                q.pop();
            }
            //cout<<available<<" ";

            meetingCount[room]++;
            int duration = meetings[i][1] - meetings[i][0];
            int start = max(meetings[i][0], mi);
            //cout<<room<<" "<<start<<" "<<start+duration<<endl;
            auto add = Room(room, start+duration);
            q.push(add);
            for(int j = 0; j < temp.size(); j++) {
                if(temp[j].roomNo != room)
                q.push(temp[j]);
            }
        }
        for(auto it:meetingCount) {
            if(mx < it.second) {
                mx = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};