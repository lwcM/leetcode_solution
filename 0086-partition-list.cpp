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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL) return head;
        ListNode *ans, *pre=new ListNode(-1), *cur;
        pre->next = head;
        ans = cur = pre;
        while(cur->next) {
            if(cur->next->val < x) {
                if(cur == pre) {
                    pre = pre->next;
                    cur = cur->next;
                    continue;
                }
                ListNode *tmp = cur->next->next;
                cur->next->next = pre->next;
                pre->next = cur->next;
                cur->next = tmp;
                pre = pre->next;
            }
            else
                cur = cur->next;
        }
        return ans->next;
    }
};

static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
