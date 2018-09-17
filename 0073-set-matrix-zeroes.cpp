class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return;
        bool row0 = false, col0 = false;
        for(int i=0; i<matrix.size(); i++)
            if(matrix[i][0] == 0)
                col0 = true;
        for(int i=0; i<matrix[0].size(); i++)
            if(matrix[0][i] == 0)
                row0 = true;
        for(int i=1; i<matrix.size(); i++)
            for(int j=1; j<matrix[0].size(); j++)
                if(matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
        for(int i=1; i<matrix.size(); i++)
            for(int j=1; j<matrix[0].size(); j++)
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
        if(row0)
            for(int i=0; i<matrix[0].size(); i++)
                matrix[0][i] = 0;
        if(col0)
            for(int i=0; i<matrix.size(); i++)
                matrix[i][0] = 0;
            
    }
};
static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
