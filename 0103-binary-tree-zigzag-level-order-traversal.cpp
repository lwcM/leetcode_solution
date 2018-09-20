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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return vector<vector<int>>();
        vector<vector<int>> ans;
        int level=0;
        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            ans.push_back(vector<int>());
            while(sz--) {
                auto node = q.front();
                q.pop();
                ans[level].push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(level & 1) reverse(ans[level].begin(), ans[level].end());
            level++;
            
        }
        return ans;
    }
};

static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
