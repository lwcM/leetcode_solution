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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(-1), *m_1, *cur, *first, *pre;
        dummy->next = head;
        m_1 = dummy;
        int k=0;
        while(k < m-1) m_1=m_1->next, k++;
        pre = first = m_1->next;
        cur = m_1->next->next;
        for(k++; k<n; k++) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        first->next = cur;
        m_1->next = pre;
        return dummy->next;
    }
};

static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
