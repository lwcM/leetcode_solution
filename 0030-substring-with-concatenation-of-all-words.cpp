static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(words.size()==0) return {};
        vector <int> ans;
        unordered_map <string, int> wc;
        int LL = words[0].size() * words.size();
        for(int i=0; i<words.size(); i++)
            wc[words[i]]++;
        for(int i=0; i+LL<=s.size(); i++)
            if(check(i, s, words, wc))
                ans.push_back(i);
        return ans;
    }
private:
    inline bool check(int k, string &s, vector<string>& words, unordered_map <string, int> &wc) {
        unordered_map <string, int> found;
        int ll = words[0].size();
        for(int i=0; i<words.size(); i++) {
            string ss = s.substr(k+ll*i, ll);
            found[ss]++;
            if(wc[ss] < found[ss]) return false;
        }
        return true;
    }
};
