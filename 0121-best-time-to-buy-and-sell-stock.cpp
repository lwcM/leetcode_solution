class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        int ans=0, mn=prices[0];
        for(int i=1; i<prices.size(); i++) {
            if(prices[i] > mn) ans = max(ans, prices[i]-mn);
            mn = min(mn, prices[i]);
        }
        return ans;
    }
};

static const auto speedupio=[]{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
