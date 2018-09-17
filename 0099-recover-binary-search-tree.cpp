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
    TreeNode *wrong1;
    TreeNode *wrong2;
    TreeNode *premax;
    
    void recoverTree(TreeNode* root) {
        wrong1 = wrong2 = premax = nullptr;
        check_subtree(root);
        swap(wrong1->val, wrong2->val);
    }
private:
    void check_subtree(TreeNode* root) {
        if(root == NULL) return;
        check_subtree(root->left);
        if(premax && premax->val > root->val) {
            wrong2 = root;
            if(!wrong1)
                wrong1 = premax;
        }
        premax = root;
        check_subtree(root->right);
    }
};

static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

