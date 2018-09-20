class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() == 0) return true;
        int l=0, r=s.size()-1;
        while(l <= r) {
            while(l<=r && !isalnum(s[l])) l++;
            while(l<=r && !isalnum(s[r])) r--;
            if(l>r) return true;
            s[l] = tolower(s[l]);
            s[r] = tolower(s[r]);
            if(s[l] == s[r])
                l++, r--;
            else
                return false;
        }
        return true;
    }
};

static const auto speedupio=[]{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
