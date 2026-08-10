class Solution {
private: 
    set<int> vis;
    bool pos = true;
public:
    void dfs(int v, unordered_set<int> cur, vector<vector<int> >& adjList, string & ans, vector<int> & parSize) {
        char c = (char)('a' + v); 
        //cout<<c<<endl;
        if(!vis.contains(v)) {
            ans.push_back(c);
        }
        vis.insert(v);
        cur.insert(v);
        vector<pair<int, int> > sortedNeighbors;
        for(int i = 0; i < adjList[v].size(); i++) {
            if(!vis.contains(adjList[v][i])) {
                sortedNeighbors.push_back({parSize[adjList[v][i]], adjList[v][i]});
            }
            if(cur.contains(adjList[v][i])) {
                cout<<"YES";
                pos = false;
                return;
            }
        }
        sort(sortedNeighbors.begin(), sortedNeighbors.end());
        for(int i = 0; i < sortedNeighbors.size(); i++) {
            //cout<<v<<" "<<sortedNeighbors[i].second<<endl;
            dfs(sortedNeighbors[i].second, cur, adjList, ans, parSize);
        }
    }
    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        if(n == 0) {
            return "";
        }
        if(n == 1) {
            return words[0];
        }
        vector<int> par (26, 0);
        vector<vector<int> > adjList(26);
        set<int> usedChar;
        for(int i = 0; i < n-1; i++) {
            int j = 0;
            int size1 = words[i].size();
            int size2 = words[i+1].size();
            while(j < size1 && j < size2 && words[i][j] == words[i+1][j]) {
                usedChar.insert(words[i][j] - 'a');
                j++;
            }
            if (j < size1 && j == size2) {
                return "";
            }
            if(j != size1 && j != size2) {
                adjList[words[i][j] - 'a'].push_back(words[i+1][j] - 'a');
                usedChar.insert(words[i][j] - 'a');
                usedChar.insert(words[i+1][j] - 'a');
                par[words[i+1][j] - 'a']++;
            }
            int temp = j;
            while(j < size1) {
                usedChar.insert(words[i][j] - 'a');
                j++;
            }
            j = temp;
            while(i == n-2 && j < size2) {
                usedChar.insert(words[i+1][j] - 'a');
                j++;
            }
        }
        string ans = "";
        int cnt = 0;
        unordered_set<int> cur;
        for(int i = 25; i >= 0; i--) {
            if(par[i] == 0 && !vis.contains(i) && usedChar.contains(i)) {
                cnt++;
                dfs(i, cur, adjList, ans, par);
                if(!pos) {
                    return "";
                }
            }
        }
        if(!pos || ans.size() != usedChar.size()) {
            return "";
        }
        cout<<cnt;
        //cout<<usedChar.contains(25)<<" "<<par[25]<<" "<<vis.contains(25);
        return ans;
    }
};
