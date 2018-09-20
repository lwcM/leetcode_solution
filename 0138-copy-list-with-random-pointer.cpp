/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL) return head;
        unordered_map<RandomListNode *, RandomListNode *> mp;
        RandomListNode *newhead = new RandomListNode(head->label);
        RandomListNode *cur=head, *newcur=newhead;
        mp[cur] = newcur;
        while(cur->next) {
            newcur->next = new RandomListNode(cur->next->label);
            mp[cur->next] = newcur->next;
            cur = cur->next;
            newcur = newcur->next;
        }
        cur = head;
        newcur = newhead;
        while(cur) {
            newcur->random = mp[cur->random];
            cur = cur->next;
            newcur = newcur->next;
        }
        return newhead;
    }
};
