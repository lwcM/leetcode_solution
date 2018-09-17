class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==0 || n==0) return 1;
        //assume test case won't cause overflow
        long long ans=1;
        int N = m+n-2;
        if(m<n) swap(m, n);
        for(int i=N; i>=m; i--)
            ans *= i;
        for(int i=n-1; i>=2; i--)
            ans /= i;
        return ans;
    }
};
