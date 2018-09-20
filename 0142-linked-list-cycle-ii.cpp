/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next==NULL) return NULL;
        ListNode *slow = head->next, *fast = head->next->next;
        while(slow != fast) {
            if(fast == NULL || fast->next == NULL) return NULL;
            slow = slow->next;
            fast = fast->next->next;
        }
        while(head != fast) {
            head = head->next;
            fast = fast->next;
        }
        return fast;
    }
};


