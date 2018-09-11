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
                bool match=(i!=s.size() && (s[i]==p[j] || p[j]=='.'));
                if(j+1<p.size() && p[j+1] == '*')
                    dp[i][j] |= dp[i][j+2] | (match && (dp[i+1][j] | dp[i+1][j+2]));
                else
                    dp[i][j] |= (match && dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};
