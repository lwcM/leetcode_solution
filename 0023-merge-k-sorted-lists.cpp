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

struct cmp {
    bool operator() (ListNode *a, ListNode *b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        priority_queue <ListNode*, vector<ListNode*>, cmp> q;
        for(int i=0; i<lists.size(); i++)
            if(lists[i])
                q.push(lists[i]);
        while(!q.empty()) {
            ListNode* tmp = q.top();
            q.pop();
            if(tmp->next)
                q.push(tmp->next);
            tail->next = tmp;
            tail = tail->next;
        }
        tail = dummy->next;
        delete dummy;
        return tail;
    }
};
