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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* tmp=head;
        while(tmp != NULL && tmp->next != NULL) {
            if(tmp->val == tmp->next->val) {
                ListNode* x=tmp->next->next;
                delete tmp->next;
                tmp->next = tmp->next->next;
            }
            else
                tmp = tmp->next;
        }
        return head;
    }
};
static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
