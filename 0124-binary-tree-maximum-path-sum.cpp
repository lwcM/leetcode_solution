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
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        dfs(root, ans);
        return ans;
    }
    
    int dfs(TreeNode* root, int &ans) {
        if(root == NULL) return 0;
        int l = max(dfs(root->left, ans), 0);
        int r = max(dfs(root->right, ans), 0);
        ans = max(ans, l+r+root->val);
        return max(l, r)+root->val;
    }
};

static const auto speedupio=[]{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
