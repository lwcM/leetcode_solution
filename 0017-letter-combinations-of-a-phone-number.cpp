static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    unordered_map <char, string> mp = {{'2', "abc"},{'3', "def"},{'4', "ghi"},{'5', "jkl"},{'6', "mno"},{'7', "pqrs"},{'8', "tuv"},{'9', "wxyz"}};
    void dfs(string &d, string &ans, int idx, vector <string> &v) {
        if(idx == ans.size()) {
            if(ans.size()>0)
                v.push_back(ans);
            return;
        }
        for(int i=0; i<mp[d[idx]].size(); i++){
            ans[idx] = mp[d[idx]][i];
            dfs(d, ans, idx+1, v);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector <string> v;
        string tmp(digits);
        dfs(digits, tmp, 0, v);
        return v;
    }
};
