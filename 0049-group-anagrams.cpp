static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, int> mp;
        vector<vector<string>> ans;
        int cnt=0;
        for(auto str:strs) {
            string ss = str;
            sort(ss.begin(), ss.end());
            if(mp.find(ss) == mp.end()) {
                mp[ss] = cnt;
                ans.push_back({str});
                cnt++;
            }
            else
                ans[mp[ss]].push_back(str);
        }
        return ans;
    }
};
