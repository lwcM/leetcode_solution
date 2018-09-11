static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    void dfs(int k, string &s, int depth, vector<string> &ans, int &n){
        if(k == 2*n) {
            ans.push_back(s);
            return;
        }
        if(depth < 2*n-k) {
            s[k] = '(';
            dfs(k+1, s, depth+1, ans, n);
        }
        if(depth) {
            s[k] = ')';
            dfs(k+1, s, depth-1, ans, n);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector <string> ans;
        string tmp="";
        for(int i=0; i<2*n; i++)
            tmp += '(';
        dfs(0, tmp, 0, ans, n);
        return ans;
    }
};
