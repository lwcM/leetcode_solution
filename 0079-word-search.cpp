class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++)
            for(int j=0; j<board[0].size(); j++)
                if(dfs(0, i, j, board, word))
                    return true;
        return false;
    }
    
    bool dfs(int k, int x, int y, vector<vector<char>>& board, string &word) {
        if(x<0 || y<0 || x>=board.size() || y>=board[0].size() || word[k] != board[x][y])
            return false;
        if(k == word.size()-1)
            return true;
        board[x][y] = '#';
        if (dfs(k+1, x+1, y, board, word)) return true;
        if (dfs(k+1, x, y+1, board, word)) return true;
        if (dfs(k+1, x-1, y, board, word)) return true;
        if (dfs(k+1, x, y-1, board, word)) return true;
        board[x][y] = word[k];
        return false;
    }
};

static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
