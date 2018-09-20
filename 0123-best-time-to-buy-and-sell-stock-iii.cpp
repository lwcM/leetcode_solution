class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        vector<vector<int>> dp(3, vector<int>(prices.size(), 0));
        int n = prices.size();
        int ans = 0;
        for(int i=1; i<=2; i++) {
            int buyNextMax = dp[i-1][0] - prices[0];
            for(int j=1; j<n; j++) {
                dp[i][j] = max(dp[i][j-1], buyNextMax+prices[j]);
                buyNextMax = max(buyNextMax, dp[i-1][j] - prices[j]);
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};

static const auto speedupio=[]{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
