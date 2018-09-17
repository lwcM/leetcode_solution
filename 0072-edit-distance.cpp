class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, 0));
        int n = word1.size(), m=word2.size();
        for(int i=0; i<=n; i++)
            dp[i][0] = i;
        for(int i=0; i<=m; i++)
            dp[0][i] = i;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1);
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (word1[i-1] == word2[j-1] ? 0:1));
            }
        }
        return dp[n][m];
    }
};

static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
