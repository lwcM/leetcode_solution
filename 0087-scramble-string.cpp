class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size() || s1.size() == 0) return false;
        int n = s1.size();
        vector<vector<vector<bool>>> dp(n + 1, vector<vector<bool>>(n, vector<bool>(n, 0)));
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                dp[1][i][j] = (s1[i] == s2[j]);
        for(int l=2; l<=n; l++)
            for(int i=0; i+l<=n; i++)
                for(int j=0; j+l<=n; j++)
                    for(int k=1; k<l; k++)
                        dp[l][i][j] = dp[l][i][j] | (dp[k][i][j] && dp[l-k][i+k][j+k]) | (dp[k][i][j+l-k] && dp[l-k][i+k][j]);
        return dp[n][0][0];
    }
};

static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
