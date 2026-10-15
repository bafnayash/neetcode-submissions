class Solution {
public:
    set<string> stop;
    map<string, int> dp;
    set<string> vis;
    int dfs(string cur, string target) {
        if(cur == target) {
            return 0;
        }
        if(stop.contains(cur)) {
            return 1e7;
        }
        if(dp.contains(cur)) {
            return dp[cur];
        }
        if(vis.contains(cur)) {
            return 1e7;
        }
        vis.insert(cur);
        vector<int> op;
        cout<<cur<<" START: \n";
        for(int i = 0; i < 4; i++) {
            string temp = cur;
            temp[i] = (cur[i] == '9') ? '0' : (char)(cur[i] + 1);
            cout<<temp<<" 1 \n";
            op.push_back(1 + dfs(temp, target));
            //temp = cur;
            temp[i] = (cur[i] == '0') ? '9' : (char)(cur[i] - 1);
            cout<<temp<<" "<<endl;
            op.push_back(1 + dfs(temp, target));
        }
        int mi = 1e7;
        for(int i = 0; i < op.size(); i++) {
            mi = min(op[i], mi);
        }
        dp[cur] = mi;
        return mi;
    }
    int openLock(vector<string>& deadends, string target) {
        for(int i = 0; i < deadends.size(); i++) {
            stop.insert(deadends[i]);
        }
        set<string> vis;
        //int ans = dfs("0000", target);
        queue<string> q;
        q.push("0000");
        int level = 0;
        if(stop.contains("0000")) {
            return -1;
        }
        while(!q.empty()) {
            int size = q.size();
            //cout<<size<<" ";
            for(int j = 0; j < size; j++) {
                string cur = q.front();
                q.pop();
                if(cur == target) {
                    return level;
                }
                //vis.insert(cur);
                for(int i = 0; i < 4; i++) {
                    string temp = cur;
                    temp[i] = (cur[i] == '9') ? '0' : (char)(cur[i] + 1);
                    //cout<<temp<<" 1 \n";
                    if(!stop.contains(temp) && !vis.contains(temp)) {
                        q.push(temp);
                        vis.insert(temp);
                    }
                    //temp = cur;
                    temp[i] = (cur[i] == '0') ? '9' : (char)(cur[i] - 1);
                    //cout<<temp<<" "<<endl;
                    if(!stop.contains(temp) && !vis.contains(temp)) {
                        q.push(temp);
                        vis.insert(temp);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};