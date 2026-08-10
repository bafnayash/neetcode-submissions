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
    ListNode* reverseListRec(ListNode* head) {
        //ListNode* start = head, prev = nullptr;
        if(head == nullptr) {
            return head;
        } else if(head->next == nullptr) {
            return new ListNode(head->val);
        } else {
            ListNode* node = reverseListRec(head->next);
            ListNode* start = node;
            while(start->next != nullptr) {
                start = start->next;
            }
            head->next = nullptr;
            start->next = head;
            return node;
        }
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = nullptr;
        while(cur) {
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }
};
