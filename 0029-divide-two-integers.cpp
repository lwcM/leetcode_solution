static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        int ret = 0;
        bool same_sign = ((dividend < 0)  == (divisor < 0));
        unsigned int dividend_abs = abs(dividend);
        unsigned int divisor_abs = abs(divisor);
        while(divisor_abs <= dividend_abs) {
            int tmp = divisor_abs, two = 1;
            while(tmp <= (dividend_abs>>1)) {
                tmp <<= 1;
                two <<= 1;
            }
            ret += two;
            dividend_abs -= tmp;
        }
        return same_sign ? ret:-ret;
    }
};
