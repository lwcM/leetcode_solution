static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int longestValidParentheses(string s) {
        vector <int> dp(s.size()+1, 0);
        int ans = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == ')') {
                int j = i-dp[i-1]-1;
                if(j>=0 && s[j]=='(')
                    dp[i] = dp[i-1] + 2 + (j >= 1 ? dp[j-1]:0);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
