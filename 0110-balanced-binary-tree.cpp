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
    bool isBalanced(TreeNode* root) {
        return dfs(root).first;
    }
    
    pair<bool, int> dfs(TreeNode* root) {
        if(root == NULL) return make_pair(true, 0);
        pair<bool, int> left = dfs(root->left);
        pair<bool, int> right = dfs(root->right);
        int height = max(left.second, right.second) + 1;
        if(!left.first || !right.first || abs(left.second-right.second)>1)
            return make_pair(false, height);
        return make_pair(true, height);
    }
};
static const auto speedupio=[]{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
