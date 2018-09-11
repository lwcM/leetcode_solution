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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
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
