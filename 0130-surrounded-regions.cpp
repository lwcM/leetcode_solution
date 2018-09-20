class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0 || board[0].size() == 0) return;
        for(int i=0; i<board.size(); i++) {
            dfs(i, 0, board);
            dfs(i, board[0].size()-1, board);
        }
        for(int i=0; i<board[0].size(); i++) {
            dfs(0, i, board);
            dfs(board.size()-1, i, board);
        }
        for(auto &row:board)
            for(auto &c:row)
                c = (c == 'O' ? 'X':(c == '#' ? 'O':c));
    }
    
    void dfs(int x, int y, vector<vector<char>>& board) {
        if(x<0 || y<0 || x>=board.size() || y>=board[0].size() || board[x][y] != 'O')
            return;
        board[x][y] = '#';
        dfs(x+1, y, board);
        dfs(x-1, y, board);
        dfs(x, y+1, board);
        dfs(x, y-1, board);
    }
};

static const auto speedupio=[]{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
