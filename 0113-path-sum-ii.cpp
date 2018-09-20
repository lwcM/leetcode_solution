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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> tmp;
        dfs(root, sum, ans, tmp);
        return ans;
    }
    
    void dfs(TreeNode* root, int sum, vector<vector<int>> &ans, vector<int> &tmp) {
        if(root == NULL) return;
        tmp.push_back(root->val);
        if(!root->left && !root->right && root->val == sum)
            ans.push_back(tmp);
        dfs(root->left, sum-root->val, ans, tmp);
        dfs(root->right, sum-root->val, ans, tmp);
        tmp.pop_back();
    }
};

static const auto speedupio=[]{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
