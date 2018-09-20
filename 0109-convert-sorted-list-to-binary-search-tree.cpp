/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* node;
    
    TreeNode* sortedListToBST(ListNode* head) {
        node = head;
        int sz = 0;
        while(head)
            head = head->next, sz++;
        return dfs(0, sz);
    }
    
    TreeNode* dfs(int l, int r) {
        if(l >= r) return nullptr;
        int m = (l+r) / 2;
        TreeNode *leftchild = dfs(l, m);
        TreeNode *root = new TreeNode(node->val);
        node = node->next;
        root->left = leftchild;
        root->right = dfs(m+1, r);
        return root;
    }
};

static const auto speedupio=[]{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
