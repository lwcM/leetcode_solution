class Solution {
public:
    int lengthOfLastWord(string s) {
        int tail=s.size()-1, ans=0;
        while(tail>=0 && s[tail]==' ') tail--;
        while(tail>=0 && s[tail]!=' ') tail--, ans++;
        return ans;
    }
};


static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
