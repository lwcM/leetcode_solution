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
    ListNode *dummy = new ListNode(-1);
    
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *slow = head->next, *tmp=head;
        ListNode *fast = head->next->next;
        while(fast && fast->next){
            tmp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        tmp->next = NULL;
        return mergeTwoLists(sortList(head), sortList(slow));
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *go = dummy;
        while(l1 && l2) {
            if(l1->val < l2->val){
                go->next = l1;
                l1 = l1->next;
            }
            else {
                go->next = l2;
                l2 = l2->next;
            }
            go = go->next;
        }
        go->next = l1 ? l1:l2;
        return dummy->next;
        
    }
};
static const auto speedupio=[]{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
