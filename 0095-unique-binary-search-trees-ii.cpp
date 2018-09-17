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
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return vector<TreeNode*>();
        return construct_subtree(1, n);
    }
    
    vector<TreeNode*> construct_subtree(int l, int r) {
        vector<TreeNode*> ret;
        if(l > r)
            ret.push_back(nullptr);
        else if(l == r)
            ret.push_back(new TreeNode(l));
        else {
            for(int k=l; k<=r; k++) {
                vector<TreeNode*> lt = construct_subtree(l, k-1);
                vector<TreeNode*> rt = construct_subtree(k+1, r);
                for(int i=0; i<lt.size(); i++) {
                    for(int j=0; j<rt.size(); j++) {
                        TreeNode* root = new TreeNode(k);
                        root->left = lt[i];
                        root->right = rt[j];
                        ret.push_back(root);
                    }
                }
            }
        }
        return ret;
    }
};

static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
