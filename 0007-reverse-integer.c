int reverse(int x) {
    #define INT_MAX 2147483647
    #define INT_MIN -2147483648
    long long ans = 0;
    int neg = 1;
    if (x < 0) {
        x = -x;
        neg = -1;
    }
    while (x) {
        ans = ans * 10 + x % 10;
        x /= 10;
        if (ans * neg > INT_MAX || ans * neg < INT_MIN)
            return 0;
    }
    return ans * neg;
}
