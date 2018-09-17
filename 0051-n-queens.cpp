static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> bd;
        dfs(0, 0, 0, 0, ans, n, bd);
        return ans;
    }
private:
    void dfs(int k, int lmask, int rmask, int colmask, vector<vector<string>> &ans, int &n, vector<int> &bd) {
        if(k == n) {
            vector <string> v;
            for(int x:bd) {
                int cnt=0;
                while(x) x>>=1, cnt++;
                string tmp(n, '.');
                tmp[cnt-1] = 'Q';
                v.push_back(tmp);
            }
            ans.push_back(v);
            return;
        }
        int mask = ~(lmask | rmask | colmask);
        while(mask & ((1<<n)-1)) {
            int pos = mask & (-mask);
            mask -= pos;
            bd.push_back(pos);
            dfs(k+1, (lmask|pos)<<1, (rmask|pos)>>1, colmask|pos, ans, n, bd);
            bd.pop_back();
        }
    }
};
