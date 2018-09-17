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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        int len=1;
        ListNode* tail = head;
        while(tail->next) tail=tail->next, len++;
        k %= len;
        if(k) {
            ListNode* tmp=head;
            k = len-k;
            while(--k) tmp=tmp->next;
            tail->next = head;
            head = tmp->next;
            tmp->next = NULL;
        }
        return head;
    }
};
static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
