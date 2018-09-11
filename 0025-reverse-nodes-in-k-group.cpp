/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *tail=head;
        for(int i=0; i<k; i++) {
            if(tail == NULL)
                return head;
            if(i<k-1)
                tail = tail->next;
        }
        ListNode *l=head, *r=head->next;
        l->next = reverseKGroup(tail->next, k);
        for(int i=1; i<k; i++) {
            ListNode *tmp = r->next;
            r->next = l;
            l = r;
            r = tmp;
        }
        return tail;
    }
};
