class Solution {
public:
    bool reachPacific(int i, int j, int prev, vector<vector<int>>& heights, vector<vector<int> >& reachP) {
        int n = heights.size();
        int m = heights[0].size();
        if(i < 0 || j < 0 || i >= n || j >= m || heights[i][j] == -1 || prev < heights[i][j]) {
            return false;
        }
        if(i == 0 || j == 0 || reachP[i][j] == 1) {
            reachP[i][j] = true;
            return true;
        }
        if(reachP[i][j] != -1) {
            return reachP[i][j];
        }
        int temp = heights[i][j];
        heights[i][j] = -1;
        bool ans = reachPacific(i-1, j, temp, heights, reachP);
        if(!ans)
        ans |= reachPacific(i, j-1, temp, heights, reachP);
        if(!ans)
        ans |= reachPacific(i+1, j, temp, heights, reachP);
        if(!ans)
        ans |= reachPacific(i, j+1, temp, heights, reachP);
        heights[i][j] = temp;
        reachP[i][j] = (reachP[i][j] == -1) ? ans : reachP[i][j] || ans;
        return reachP[i][j];
    }
    /*bool reachPacific(int i, int j, vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        queue<vector<int> > q;
        q.push({i,j});
        set<string> s;
        while(!q.empty()) {
            vector<int> cur = q.front();
            q.pop();
            string curPos = to_string(i) + "_" + to_string(j);
            s.insert(curPos);
            //cout<<cur[0]<<" "<<cur[1]<<endl;
            if(cur[0] == 0 || cur[1] == 0) {
                return true;
            }
            string pos = to_string(i-1) + "_" + to_string(j);
            if(i >= 1 && heights[i-1][j] <= heights[i][j] && !s.contains(pos)) {
                q.push({i-1,j});
            }
            pos = to_string(i) + "_" + to_string(j-1);
            if(j >= 1 && heights[i][j-1] <= heights[i][j] && !s.contains(pos)) {
                q.push({i,j-1});
            }
            pos = to_string(i+1) + "_" + to_string(j);
            if(i < n-1 && heights[i+1][j] <= heights[i][j] && !s.contains(pos)) {
                q.push({i+1,j});
            }
            pos = to_string(i) + "_" + to_string(j+1);
            if(j < m-1 && heights[i][j+1] <= heights[i][j] && !s.contains(pos)) {
                q.push({i,j+1});
            }
        }
        return false;
    }*/
    bool reachAtlantic(int i, int j, int prev, vector<vector<int>>& heights, vector<vector<int> > &reachA) {
        int n = heights.size();
        int m = heights[0].size();
        if(i < 0 || j < 0 || i >= n || j >= m || heights[i][j] == -1 || prev < heights[i][j] || reachA[i][j] == 0) {
            return false;
        }
        if(i == n-1 || j == m-1 || reachA[i][j] == 1) {
            reachA[i][j] = true;
            return true;
        }
        if(reachA[i][j] != -1) {
            return reachA[i][j];
        }
        int temp = heights[i][j];
        heights[i][j] = -1;
        bool ans = reachAtlantic(i+1, j, temp, heights, reachA);
        if(!ans)
        ans |= reachAtlantic(i, j+1, temp, heights, reachA);
        if(!ans)
        ans |= reachAtlantic(i-1, j, temp, heights, reachA);
        if(!ans)
        ans |= reachAtlantic(i, j-1, temp, heights, reachA);
        heights[i][j] = temp;
        reachA[i][j] = (reachA[i][j] == -1) ? ans : reachA[i][j] || ans;
        return reachA[i][j];
    }
    /*bool reachAtlantic(int i, int j, vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        queue<vector<int> > q;
        q.push({i,j});
        while(!q.empty()) {
            vector<int> cur = q.front();
            q.pop();
            if(cur[0] == n-1 || cur[1] == m-1) {
                return true;
            }
            if(i < n-1 && heights[i+1][j] <= heights[i][j]) {
                q.push({i+1,j});
            }
            if(j < m-1 && heights[i][j+1] <= heights[i][j]) {
                q.push({i,j+1});
            }
            if(i >= 1 && heights[i-1][j] <= heights[i][j]) {
                q.push({i-1,j});
            }
            if(j >= 1 && heights[i][j-1] <= heights[i][j]) {
                q.push({i,j-1});
            }
        }
        return false;
    }*/
    pair<bool,bool> reachPA(int i, int j, int prev, vector<vector<int>>& heights, vector<vector<int> >& reachP, vector<vector<int> > & reachA) {
        int n = heights.size();
        int m = heights[0].size();
        if(i < 0 || j < 0 || i >= n || j >= m || heights[i][j] == -1 || prev < heights[i][j]) {
            return {false, false};
        }
        if(i == 0 || j == 0 || reachP[i][j] == 1) {
            reachP[i][j] = 1;
        }
        if(i == n-1 || j == m-1 || reachA[i][j] == 1) {
            reachA[i][j] = 1;
        }
        if(reachP[i][j] == 1 && reachA[i][j] == 1) {
            return {reachP[i][j], reachA[i][j]};
        }
        //if(reachA[i][j] != -1 && reachP[i][j] != -1) {
         //   return {reachP[i][j], reachA[i][j]};
        //}
        int temp = heights[i][j];
        heights[i][j] = -1;
        pair<bool, bool> ans = reachPA(i-1, j, temp, heights, reachP, reachA);
        pair<bool, bool> ans2 = reachPA(i, j-1, temp, heights, reachP, reachA);
        pair<bool, bool> ans3 = reachPA(i+1, j, temp, heights, reachP, reachA);
        pair<bool, bool> ans4 = reachPA(i, j+1, temp, heights, reachP, reachA);
        heights[i][j] = temp;
        bool fi = ans.first || ans2.first  || ans3.first || ans4.first;
        bool se = ans.second || ans2.second || ans3.second || ans4.second;
        reachP[i][j] = (reachP[i][j] == -1) ? fi : reachP[i][j] || fi;
        reachA[i][j] = (reachA[i][j] == -1) ? se: reachA[i][j] || se;
        return {reachP[i][j], reachA[i][j]};
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int> > ans;
        vector<vector<int> > reachP(n, vector<int> (m, -1));
        vector<vector<int> > reachA(n, vector<int> (m, -1));
        for(int i = 0; i < n; i++) {
            reachP[i][0] = 1;
            reachA[i][m-1] = 1;
        }
        for(int i = 0; i < m; i++) {
            reachP[0][i] = 1;
            reachA[n-1][i] = 1;
        }
        //cout<<reachP[0][0]<<" "<<reachA[0][0]<<endl;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                /*pair<bool, bool> p = {reachP[i][j] == 1, reachA[i][j] == 1};
                if(reachP[i][j] == -1 || reachA[i][j] == -1) {
                    p = reachPA(i, j, 1e6, heights, reachP, reachA);
                }
                cout<<i<<" "<<j<<" "<<reachP[1][4]<<" "<<reachA[1][4]<<endl;
                if(p.first && p.second) {
                    ans.push_back({i, j});
                }*/
                bool p = reachPacific(i, j, 1e6, heights, reachP);
                bool a = reachAtlantic(i, j, 1e6, heights, reachA); 
                if(p && a) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
