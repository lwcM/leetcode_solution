class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        int ans=INT_MAX, left=0, pos=0, num=t.size();
        for(auto c:t) mp[c]++;
        for(int i=0; i<s.size(); i++) {
            if(mp[s[i]]-- > 0) num--;
            while(num == 0) {
                if(ans > i-left+1) {
                    ans = i-left+1;
                    pos = left;
                }
                if(mp[s[left++]]++ == 0) num++;
            }
        }
        return ans == INT_MAX ? "":s.substr(pos, ans);
    }
};

static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
