class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0) return vector<vector<int>>();
        vector<vector<int>> ans(numRows, vector<int>());
        ans[0].push_back(1);
        for(int i=1; i<numRows; i++) {
            ans[i].push_back(1);
            for(int j=1; j<i; j++)
                ans[i].push_back(ans[i-1][j-1]+ans[i-1][j]);
            ans[i].push_back(1);
        }
        return ans;
    }
};

static const auto speedupio=[]{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
