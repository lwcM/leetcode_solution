class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        int l=1, r=46341, ans=0;
        while(l<r) {
            int m=(l+r)/2;
            if(m*m <= x){
                l = m+1;
                ans = m;
            }
            else
                r = m;
        }
        return ans;
    }
};
static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
