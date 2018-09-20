class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for(int i=1; i<prices.size(); i++)
            if(prices[i] > prices[i-1])
                ans += prices[i] - prices[i-1];
        return ans;
    }
};

static const auto speedupio=[]{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
