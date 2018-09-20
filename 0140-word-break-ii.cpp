class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector <bool> dp(s.size()+1, false);
        vector<string> ans;
        dp[0] = true;
        for(int i=1; i<=s.size(); i++) {
            for(int j=0; j<wordDict.size(); j++) {
                if(i >= wordDict[j].size() && s.substr(i-wordDict[j].size(), wordDict[j].size()) == wordDict[j]) {
                    if(dp[i-wordDict[j].size()]) {
                        dp[i] = true;
                    }
                }
            }
        }
        if(!dp[s.size()]) return ans;
        string tmp="";
        dfs(0, tmp, s, wordDict, ans);
        return ans;
    }
    
    void dfs(int k, string tmp, string &s, vector<string>& wordDict, vector<string> &ans) {
        if(k == s.size()) {
            ans.emplace_back(tmp.substr(1));
            return;
        }
        for(int l=0; l<wordDict.size(); l++) {
            if(k+wordDict[l].size()<=s.size() && s.substr(k, wordDict[l].size()) == wordDict[l]) {
                dfs(k+wordDict[l].size(), tmp+" "+wordDict[l], s, wordDict, ans);
            }
        }
    }
};

static const auto speedupio=[]{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
