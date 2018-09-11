static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool isMatch(string s, string p) {
        bool **dp = new bool*[s.size()+1];
        for(int i = 0; i < s.size()+1; ++i)
            dp[i] = new bool[p.size()+1]();
        dp[s.size()][p.size()] = true;
        for(int i=s.size(); i>=0; i--) {
            for(int j=p.size()-1; j>=0; j--) {
                if(i<s.size() && (s[i] == p[j] || p[j] == '?'))
                    dp[i][j] |= dp[i+1][j+1];
                if(p[j] == '*')
                    dp[i][j] |= dp[i][j+1] | (i<s.size() && (dp[i+1][j+1] | dp[i+1][j]));
            }
        }
        return dp[0][0];
    }
};
