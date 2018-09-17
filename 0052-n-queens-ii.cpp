static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        dfs(0, 0, 0, 0, ans, n);
        return ans;
    }
private:
    void dfs(int k, int lmask, int rmask, int colmask, int &ans, int &n) {
        if(k == n) {
            ans++;
            return;
        }
        int mask = ~(lmask | rmask | colmask);
        while(mask & ((1<<n)-1)) {
            int pos = mask & (-mask);
            mask -= pos;
            dfs(k+1, (lmask|pos)<<1, (rmask|pos)>>1, colmask|pos, ans, n);
        }
    }
};
