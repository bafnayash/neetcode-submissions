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
    ListNode* reverseList(ListNode* head) {
        ListNode* start = head;
        ListNode* prev = nullptr;
        while(head) {
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* reversed = reverseList(head);
        ListNode* cur = reversed;
        if(n==1) {
            return reverseList(cur->next);
        }
        int count = 2;
        while(cur) {
            if(count == n) {
                ListNode*temp = cur->next;
                if(temp) {
                    cur->next = cur->next->next;
                    //return head;
                } else {
                    cur->next = nullptr;
                    //return h
                }
                return reverseList(reversed);
            }
            count++;
            cur = cur->next;
        }
    }
};
