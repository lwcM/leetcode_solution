static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long long rev=0, tmp=x;
        while(tmp) {
            rev = rev * 10 + tmp % 10;
            tmp /= 10;
        }
        return rev == x;
    }
};
