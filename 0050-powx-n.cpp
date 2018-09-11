static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    double myPow(double x, int n) {
        return n >= 0 ? mod(x, n):1/mod(x, -n);
    }
    double mod(double x, int n) {
        if(n == 0) return 1;
        double tmp = mod(x, n/2);
        return n & 1 ? tmp*tmp*x:tmp*tmp;
    }
};
