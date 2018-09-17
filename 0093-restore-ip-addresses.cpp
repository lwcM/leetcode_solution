class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string tmp="";
        dfs(0, 0, 0, ".", ans, s);
        return ans;
    }
    
    void dfs(int i, int num, int dot, string tmp, vector<string> &ans, string &s) {
        if(i == s.size()) {
            if(dot == 3 && tmp.size() && tmp[tmp.size()-1] != '.')
                ans.push_back(tmp.substr(1));
            return;
        }
        if(num*10+s[i]-'0' <= 255 && (tmp.size()<2  || tmp[tmp.size()-2] != '.' || tmp[tmp.size()-1] != '0')  )
            dfs(i+1, num*10+s[i]-'0', dot, tmp+s[i], ans, s);
        if(dot < 3 && tmp.size() && tmp[tmp.size()-1] != '.')
            dfs(i, 0, dot+1, tmp+'.', ans, s);
    }
};

static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
