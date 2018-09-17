class Solution {
public:
    int fac[10];
    string getPermutation(int n, int k) {
        fac[0]=fac[1] = 1;
        for(int i=2; i<10; i++) fac[i] = i * fac[i-1];
        vector<bool> used(n+1, false);
        string ans(n, '0');
        dfs(0, k, n, ans, used);
        return ans;
    }
private:
    void dfs(int x, int k, int &n, string &ans, vector<bool> &used) {
        if(k == 1) {
            for(int i=1; i<=n; i++)
                if(!used[i])
                    ans[x++] = i+'0';
            return;
        }
        int tmp=k/fac[n-x-1]+(k%fac[n-x-1] != 0);
        int num=0, cn = (tmp-1)*fac[n-x-1];
        while(tmp) {
            num++;
            if(!used[num])
                tmp--;
        }
        ans[x] = num+'0';
        used[num] = true;
        dfs(x+1, k-cn, n, ans, used);
    }
};

static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
