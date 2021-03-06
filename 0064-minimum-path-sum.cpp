class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        dp[0][0] = grid[0][0];
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i > 0)
                    dp[i][j] = min(dp[i][j], grid[i][j]+dp[i-1][j]);
                if(j > 0)
                    dp[i][j] = min(dp[i][j], grid[i][j]+dp[i][j-1]);
            }
        }
        return dp[n-1][m-1];
    }
};
static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
