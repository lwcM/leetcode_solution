class Solution {
public:
    int climbStairs(int n) {
        int a=0,b=1,c=1;
        for(int i=2; i<=n; i++)
            a=b,b=c,c=a+b;
        return c;
    }
};
static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
