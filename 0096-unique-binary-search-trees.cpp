class Solution {
public:
    int numTrees(int n) {
        vector <int> dp(n+1, 0);
        dp[0] = dp[1] = 1;
        dp[2] = 2;
        for(int i=3; i<=n; i++)
            for(int j=1; j<=i; j++)
                dp[i] += dp[j-1]*dp[i-j];
        return dp[n];
        
    }
};

static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
