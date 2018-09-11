static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    bool rr[9][10], cc[9][10], di[3][3][10];
    void solveSudoku(vector<vector<char>>& board) {
        memset(rr, 0, sizeof(rr));
        memset(cc, 0, sizeof(cc));
        memset(di, 0, sizeof(di));
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(board[i][j] != '.') {
                    rr[i][board[i][j]-'0'] = true;       
                    cc[j][board[i][j]-'0'] = true;
                    di[i/3][j/3][board[i][j]-'0'] = true;
                }
            }
        }
        dfs(0, 0, board);
    }
private:
    bool dfs(int x, int y, vector<vector<char>>& board) {
        if(y == 9)
            x++, y=0;
        if(x == 9)
            return true;
        if(board[x][y] != '.')
            return dfs(x, y+1, board);
        for(int i=1; i<=9; i++) {
            if(!rr[x][i] && !cc[y][i] && !di[x/3][y/3][i]) {
                board[x][y] = i+'0';
                rr[x][i] = cc[y][i] = di[x/3][y/3][i] = true;
                if(dfs(x, y+1, board)) return true;
                rr[x][i] = cc[y][i] = di[x/3][y/3][i] = false;
                board[x][y] = '.';
            }
        }
        return false;
    }
};
