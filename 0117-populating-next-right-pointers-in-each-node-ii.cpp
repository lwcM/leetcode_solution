/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) return;
        TreeLinkNode *tmp = root->left;
        if(root->right) {
            if(tmp) tmp->next = root->right;
            tmp = root->right;
        }
        if(tmp) {
            TreeLinkNode *tmproot = root->next;
            while(tmproot && !tmp->next) {
                if(tmproot->left)
                    tmp->next = tmproot->left;
                else if(tmproot->right) 
                    tmp->next = tmproot->right;
                else 
                    tmproot = tmproot->next;
            }
        }
        connect(root->right);
        connect(root->left);
        
    }
};
