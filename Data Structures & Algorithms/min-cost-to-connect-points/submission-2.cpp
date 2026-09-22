class Solution {
public:
    struct Vertex {
        int x,y;
        Vertex(vector<int> v) {
            x = v[0];
            y = v[1];
        }
        Vertex() {
            x = 0;
            y = 0;
        }
    };
    struct Edge {
        int cost;
        vector<int> src;
        vector<int> dest;
        Edge(int cost, vector<int> s, vector<int> d) {
            this->cost = cost;
            this->src = s;
            this->dest = d;
        }
        Edge() {
            cost = 0; 
            src = {0, 0};
            dest = {0, 0};
        }
        bool operator>(const Edge & other) const {
            return this->cost > other.cost;
        }
    };
    int getCost(vector<int>& p1, vector<int>& p2) {
        int i = p1[0];
        int j = p1[1];
        int x = p2[0];
        int y = p2[1];
        return abs(i-x) + abs(j-y);
    }
    map<vector<int>, vector<int> > par; 
    map<vector<int>, int> size;
    vector<int> getParent(vector<int> v1) {   
        while(v1 != par[v1]) {
            v1 = par[v1];
        }
        return v1;
    }
    bool merge(vector<int>& v1, vector<int>& v2) {
        auto par1 = getParent(v1);
        auto par2 = getParent(v2);
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
        return true;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<Edge, vector<Edge>, greater<Edge> > q;
        for(int i = 0; i < n; i++) {
            par[points[i]] = points[i];
            size[points[i]] = 1;
            for(int j = i+1; j < n; j++) {
                if(i != j) {
                    q.push({getCost(points[i], points[j]), points[i], points[j]});
                    //q.push({getCost(points[i], points[j]), points[j], points[i]});
                }
            }
        }
        int ans = 0;
        while(!q.empty()) {
            auto [cost, s, d] = q.top();
            q.pop();
            if(size[s] == n || size[d] == n) {
                return ans;
            }
            //cout<<s[0]<<" "<<s[1]<<" "<<d[0]<<" "<<d[1]<<" "<<cost<<endl;
            if(merge(s, d)) {
                ans += cost;
            }
        }
        return ans;
    }
};
