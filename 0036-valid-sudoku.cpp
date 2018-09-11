static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool r[9][10]={0}, c[9][10]={0}, cl[3][3][10]={0};
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[i].size(); j++) {
                if(board[i][j] == '.')
                    continue;
                if(r[i][board[i][j]-'0'] || c[j][board[i][j]-'0'] || cl[i/3][j/3][board[i][j]-'0'])
                    return false;
                r[i][board[i][j]-'0'] = true;
                c[j][board[i][j]-'0'] = true;
                cl[i/3][j/3][board[i][j]-'0'] = true;
            }
        }
        return true;
    }
};
