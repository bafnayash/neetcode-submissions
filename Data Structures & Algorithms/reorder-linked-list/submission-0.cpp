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
    void reorderList(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* secondHalf = slow->next;
        slow->next = nullptr;
        ListNode* reversed = reverseList(secondHalf);
        ListNode* cur = head;
        while(reversed) {
            ListNode* temp = cur->next;
            ListNode* temp2 = reversed->next;
            reversed->next = temp;
            cur->next = reversed;
            cur = temp;
            reversed = temp2;
        }
    }
};
