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
    bool isValidBST(TreeNode* root) {
        return check_subtree(root, LONG_MIN, LONG_MAX);
    }
private:
    bool check_subtree(TreeNode* root, long mn, long mx) {
        if(root == NULL) return true;
        if(root->val <= mn || root->val >= mx) return false;
        if(root->left && (!check_subtree(root->left, mn, root->val))) return false;
        if(root->right && (!check_subtree(root->right, root->val, mx))) return false;
        return true;
    }
};

static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
