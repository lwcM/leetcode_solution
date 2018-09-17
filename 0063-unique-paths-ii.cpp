class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size()==0 || obstacleGrid[0].size()==0) return 1;
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = !obstacleGrid[0][0];
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(obstacleGrid[i][j] == 0) {
                    dp[i][j] += (i > 0 ? dp[i-1][j]:0);
                    dp[i][j] += (j > 0 ? dp[i][j-1]:0);
                }        
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
