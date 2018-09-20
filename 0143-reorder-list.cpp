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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;
        ListNode *slow = head, *fast=head, *preTail=head;
        while(fast && fast->next) {
            preTail = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        preTail->next = NULL;
        ListNode *l2 = reverseList(slow);
        head = mergeList(head, l2);
    }
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* pre=NULL, *cur=head;
        while(cur) {
            ListNode* tmp=cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
    void print(ListNode* head) {
        while(head) {
            cout<<head->val<<endl;
            head=head->next;
        }
    }
    ListNode* mergeList(ListNode* l1, ListNode* l2) {
        ListNode* head = l1, *pre = l1;
        while(l1 && l2) {
            pre = l2;
            ListNode* tmp = l1->next;
            l1->next = l2;
            l2 = l2->next;
            l1->next->next = tmp;
            l1 = tmp;
        }
        if(l2) pre->next = l2;
        return head;
    }
};
static const auto speedupio=[]{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
