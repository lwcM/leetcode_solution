class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0) return 1;
        vector<int> dp(s.size()+1, 0);
        dp[0] = 1;
        for(int i=1; i<=s.size(); i++) {
            if(s[i-1] != '0')
                dp[i] += dp[i-1];
            if(i >= 2 && s[i-2] != '0' && (s[i-2]-'0')*10+(s[i-1]-'0') <= 26)
                dp[i] += dp[i-2];
        }
        return dp[s.size()];
    }
};

static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
