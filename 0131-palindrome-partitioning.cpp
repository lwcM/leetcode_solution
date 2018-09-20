class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> v;
        vector<vector<string>> ans;
        dfs(0, s, v, ans);
        return ans;
    }
    
    void dfs(int k, string &s, vector<string> &v, vector<vector<string>> &ans) {
        if(k == s.size()) {
            ans.push_back(v);
            return;
        }
        string ss="";
        for(int i=k; i<s.size(); i++) {
            ss += s[i];
            if(isPal(ss)) {
                v.emplace_back(ss);
                dfs(i+1, s, v, ans);
                v.pop_back();
            }
        }
    }
    
    bool isPal(string &s) {
        for(int i=0; i<s.size()/2; i++)
            if(s[i] != s[s.size()-i-1])
                return false;
        return true;
    }
};

static const auto speedupio=[]{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
