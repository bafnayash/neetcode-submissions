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
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> vis;
        ListNode* start = head;
        while(head) {
            if(vis.contains(head)) {
                return true;
            } 
            vis.insert(head);
            head = head->next;
        }
        return false;
    }
};
