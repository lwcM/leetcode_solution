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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return dfs(0, postorder.size(), 0, inorder.size(), inorder, postorder);
    }
    
    TreeNode* dfs(int postl, int postr, int inl, int inr, vector<int>& inorder, vector<int>& postorder) {
        if(postl >= postr || inl >= inr) return nullptr;
        TreeNode* root = new TreeNode(postorder[postr-1]);
        int rtidx = inl;
        while(inorder[rtidx] != postorder[postr-1]) rtidx++;
        root->left = dfs(postl, postl+rtidx-inl, inl, rtidx, inorder, postorder);
        root->right = dfs(postl+rtidx-inl, postr-1, rtidx+1, inr, inorder, postorder);
        return root;
    }
};

static const auto speedupio=[]{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
