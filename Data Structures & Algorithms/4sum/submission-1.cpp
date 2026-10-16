class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<long> > ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                long curTarget = (long)target - nums[i] - nums[j];
                unordered_map<long, vector<long> > remaining;
                for(int k = j+1; k < n; k++) {
                    remaining[nums[k]].push_back(k);
                } 
                for(int k = j+1; k < n; k++) {
                    if(remaining.contains(curTarget - nums[k]) && nums[k] <= curTarget - nums[k]) {
                        vector<long> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        temp.push_back(curTarget-nums[k]);
                        if(remaining[curTarget - nums[k]].size() > 1 || remaining[curTarget - nums[k]][0] != k) {
                            ans.insert(temp);
                        }
                    }
                }
               /* while(st < en && en < n) {
                    if(nums[st] + nums[en] == curTarget) {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[st]);
                        temp.push_back(nums[en]);
                        ans.insert(temp);
                        if(st < en-1) {
                            st++;
                        } else {
                            en++;
                        }
                    } else if(nums[st] + nums[en] < curTarget && st < en-1) {
                        st++;
                    } else if(nums[st] + nums[en] < curTarget) {
                        en++;
                    } else {
                        break;
                    }
                }*/
            }
        }
        vector<vector<int> > final;
        for(auto it:ans) {
            vector<int> temp;
            for(auto ele:it) {
                temp.push_back(ele);
            }
            final.push_back(temp);
        }
        return final;
    }
};