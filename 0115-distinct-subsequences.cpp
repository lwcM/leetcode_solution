class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(t.size()+1, vector<int>(s.size()+1, 0));
        for(int j=0; j<=s.size(); j++)
            dp[0][j] = 1;
        for(int i=1; i<=t.size(); i++) {
            for(int j=1; j<=s.size(); j++) {
                if(t[i-1] == s[j-1])
                    dp[i][j] += dp[i-1][j-1];
                dp[i][j] += dp[i][j-1];
            }
        }
        return dp[t.size()][s.size()];
                
    }
};

static const auto speedupio=[]{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
