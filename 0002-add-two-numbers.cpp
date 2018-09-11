/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

static const auto __ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1), *ans;
        ans = dummy;
        int carry = 0;
        while(l1 || l2) {
            ans->next = new ListNode((l1 ? l1->val:0) + (l2 ? l2->val:0) + carry);
            carry = 0;
            ans = ans->next;
            if(ans->val >= 10) {
                ans->val -= 10;
                carry = 1;
            }
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }
        if(carry)
            ans->next = new ListNode(carry);
        return dummy->next;
    }
};
