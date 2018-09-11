static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0; i<n; i++)
            for(int j=0; j<n-i-1; j++)
                swap(matrix[i][j], matrix[n-j-1][n-i-1]);
        for(int j=0; j<n; j++)
            for(int i=0; i<n/2; i++)
                swap(matrix[i][j], matrix[n-i-1][j]);
    }
};
