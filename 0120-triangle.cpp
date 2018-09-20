class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i=1; i<triangle.size(); i++) {
            triangle[i][0] += triangle[i-1][0];
            for(int j=1; j<triangle[i].size()-1; j++)
                triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
            triangle[i][i] += triangle[i-1][i-1];
        }
        int mn=INT_MAX;
        for(int j=0; j<triangle[triangle.size()-1].size(); j++)
            mn = min(mn, triangle[triangle.size()-1][j]);
        return mn;
    }
};

static const auto speedupio=[]{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
