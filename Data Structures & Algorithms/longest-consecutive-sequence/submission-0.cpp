class Solution {
public:
    int find(int i, vector<int> & parent) {
        while(parent[i] != i) {
            i = parent[i];
        }
        return i;
    }
    void unionSet(int i, int j, vector<int> & parent, vector<int> & size, vector<int>& nums) {
        int parent1 = find(i, parent);
        int parent2 = find(j, parent);
        if(nums[parent1] < nums[parent2]) {
            parent[j] = parent1;
            size[parent1] += size[parent2]; 
        } else if(nums[parent1] > nums[parent2]){
            parent[i] = parent2;
            size[parent2] += size[parent1];
        }
        /*cout<<"Parent: ";
        for(int k = 0; k < nums.size(); k++) {
            cout<<parent[k]<<" ";
        }
        cout<<"Size: ";
        for(int k = 0; k < nums.size(); k++) {
            cout<<size[k]<<" ";
        }
        cout<<endl;*/
    }
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        vector<int> parent(n, -1);
        vector<int> size(n,1);
        int ans = 0;
        unordered_map<int, int> pos;
        for(int i = 0; i < n; i++) {
            parent[i] = i;   
            pos[nums[i]] = i;
        }
        for(int i = 0; i < n; i++) {
            parent[i] = i;   
        }
        for(auto it:pos) {
            //cout<<it.first<<" Start: ";
            if(pos.contains(it.first+1)) {
                unionSet(it.second, pos[it.first+1], parent, size, nums);
            }
            if(pos.contains(it.first-1)) {
                unionSet(it.second, pos[it.first-1], parent, size, nums);
            }
        }
        for(int i = 0; i < n; i++) {
            //cout<<size[i]<<" ";
            ans = max(ans, size[i]);
        }
        return ans;
    }
};
