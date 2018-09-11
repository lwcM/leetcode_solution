static const auto ___ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int a[128]={0}, ans=0, l=0;
        for(int i=0; i<s.size(); i++){
            if(a[s[i]])
                l = max(l, a[s[i]]);
            ans = max(ans, i+1-l);
            a[s[i]] = i+1;
        }
        return ans;
    }
};
