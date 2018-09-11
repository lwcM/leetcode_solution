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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* l1=head, *ans=head;
        int cnt=0;
        while(l1) {
            cnt ++;
            l1 = l1->next;
            if(cnt > n+1) {
                ans = ans->next;
            }
        }
        if(cnt == n)
            head = head->next;
        else
            ans->next = ans->next->next;
        
        return head;
    }
};
