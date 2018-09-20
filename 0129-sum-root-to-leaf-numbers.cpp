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
    int sumNumbers(TreeNode* root) {
        int ans=0;
        dfs(root, 0, ans);
        return ans;
    }
    void dfs(TreeNode* root, int num, int &ans) {
        if(root == NULL) return;
        if(root->left == NULL && root->right==NULL) {
            ans += num*10+root->val;
            return;
        }
        dfs(root->left, num*10+root->val, ans);
        dfs(root->right, num*10+root->val, ans);
    }
};

static const auto speedupio=[]{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
