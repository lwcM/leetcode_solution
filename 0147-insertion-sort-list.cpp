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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *dummy = new ListNode(INT_MIN), *cur=head;
        while(cur) {
            ListNode *pos = dummy->next, *pre = dummy;
            while(pos) {
                if(cur->val >= pre->val && cur->val <= pos->val)
                    break;
                pos = pos->next;
                pre = pre->next;
            }
            ListNode *tmp = cur->next;
            pre->next = cur;
            cur->next = pos;
            cur = tmp;
        }
        return dummy->next;
    }
};

static const auto speedupio=[]{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
