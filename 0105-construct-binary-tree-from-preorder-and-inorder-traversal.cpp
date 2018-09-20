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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(0, preorder.size(), 0, inorder.size(), preorder, inorder);
    }
    
    TreeNode* dfs(int prel, int prer, int inl, int inr, vector<int>& preorder, vector<int>& inorder) {
        if(prel >= prer || inl >= inr) return nullptr;
        TreeNode* root = new TreeNode(preorder[prel]);
        int rtidx = inl;
        while(inorder[rtidx] != preorder[prel]) rtidx++;
        root->left = dfs(prel+1, prel+1+rtidx-inl, inl, rtidx, preorder, inorder);
        root->right = dfs(prel+1+rtidx-inl, prer, rtidx+1, inr, preorder, inorder);
        return root;
    }
};

static const auto speedupio=[]{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();

