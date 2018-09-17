class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;
        int l=0, r=matrix.size(), pos=0;
        while(l<r) {
            int m = (l+r)/2;
            if(target == matrix[m][0])
                return true;
            else if(target < matrix[m][0])
                r = m;
            else {
                l = m+1;
                pos = m;
            }
        }
        l=0, r=matrix[pos].size();
        while(l<r) {
            int m = (l+r)/2;
            if(target == matrix[pos][m])
                return true;
            else if(target < matrix[pos][m])
                r = m;
            else
                l = m+1;
        }
        return false;
    }
};
static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
