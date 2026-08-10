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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* start1 = list1;
        ListNode* start2 = list2;
        ListNode* start = nullptr;
        ListNode* ans = nullptr;
        while(start1 && start2) {
            if(start1->val <= start2->val) {
                if(ans == nullptr) {
                    start = new ListNode(start1->val);
                    ans = start;
                } else {
                    ListNode* temp = new ListNode(start1->val);
                    start->next = temp; 
                    start = start->next;
                }
                start1 = start1->next;
            } else {
                if(ans == nullptr) {
                    start = new ListNode(start2->val);
                    ans = start;
                } else {
                    ListNode* temp = new ListNode(start2->val);
                    start->next = temp; 
                    start = start->next;
                }
                start2 = start2->next;
            }
        }
        while(start1) {
            if(ans == nullptr) {
                start = new ListNode(start1->val);
                ans = start;
            } else {
                ListNode* temp = new ListNode(start1->val);
                start->next = temp; 
                start = start->next;
            }
            start1 = start1->next;
        }
        while(start2) {
            if(ans == nullptr) {
                start = new ListNode(start2->val);
                ans = start;
            } else {
                ListNode* temp = new ListNode(start2->val);
                start->next = temp; 
                start = start->next;
            }
            start2 = start2->next;
        }
        return ans;
    }
};