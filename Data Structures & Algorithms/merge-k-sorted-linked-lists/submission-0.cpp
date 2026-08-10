/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int>> > pq;
        int n = lists.size();
        for(int i = 0; i < n; i++) {
            pq.push({lists[i]->val,i});
        }
        ListNode* ans = new ListNode();
        ListNode* cur = ans;
        while(!pq.empty()) {
            pair<int,int> temp = pq.top();
            pq.pop();
            cur->next = new ListNode(temp.first);
            cur = cur->next;
            if(lists[temp.second]->next) {
                lists[temp.second] = lists[temp.second]->next;
                pq.push({lists[temp.second]->val, temp.second});
            }
        }
        return ans->next;
    }
};
