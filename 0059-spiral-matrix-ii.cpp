class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int x=0, y=0, cnt=1, dd=0;
        int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};
        while(cnt <= n*n) {
            ans[x][y] = cnt++;
            if(x+dx[dd]<0 || x+dx[dd]>=n || y+dy[dd]<0 || y+dy[dd]>=n || ans[x+dx[dd]][y+dy[dd]])
                dd = (dd+1)%4;
            x += dx[dd];
            y += dy[dd];
        }
        return ans;
    }
};

static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
