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
    void flatten(TreeNode* root) {
        dfs(root);
    }
    
    TreeNode* dfs(TreeNode* root) {
        if(root == NULL) return NULL;
        TreeNode* leftTail = dfs(root->left);
        TreeNode* rightTail = dfs(root->right);
        if(leftTail) leftTail->right = root->right;
        if(root->left) root->right = root->left;
        root->left = NULL;
        if(rightTail) return rightTail;
        if(leftTail) return leftTail;
        return root;
        
    }
};
static const auto speedupio=[]{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
