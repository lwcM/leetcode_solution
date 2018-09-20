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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(0, nums.size(), nums);
    }
    
    TreeNode* dfs(int l, int r, vector<int>& nums) {
        if(l >= r) return nullptr;
        int m = (l+r)/2;
        TreeNode* root = new TreeNode(nums[m]);
        root->left = dfs(l, m, nums);
        root->right = dfs(m+1, r, nums);
        return root;
    }
};

static const auto speedupio=[]{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
