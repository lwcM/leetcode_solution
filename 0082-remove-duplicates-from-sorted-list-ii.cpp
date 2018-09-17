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
        ListNode* tmp=head, *pre=new ListNode(-1), *ans;
        pre->next = head;
        ans = pre;
        bool del=false;
        while(tmp != NULL && tmp->next != NULL) {
            if(tmp->val == tmp->next->val) {
                ListNode* x=tmp->next->next;
                tmp->next = tmp->next->next;
                del = true;
            }
            else {
                tmp = tmp->next;
                if(del)
                    pre->next = tmp;
                else
                    pre=pre->next;
                del=false;
            }
        }
        if(del && tmp)
            pre->next = tmp->next;
        return ans->next;
    }
};

static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
