class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size()==0 || matrix[0].size()==0) return vector<int>();
        vector <int> ans;
        vector <vector<bool> > visited(matrix.size(), vector<bool>(matrix[0].size(), false));
        int x=0, y=0, cnt=0, dd=0;
        int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};
        while(cnt < matrix.size()*matrix[0].size()) {
            cnt++;
            ans.push_back(matrix[x][y]);
            visited[x][y] = true;
            if(x+dx[dd]<0 || x+dx[dd]>=matrix.size() || y+dy[dd]<0 || y+dy[dd]>=matrix[0].size() || visited[x+dx[dd]][y+dy[dd]])
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
