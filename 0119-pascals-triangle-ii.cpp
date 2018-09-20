class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1, 0);
        ans[0] = 1;
        for(int i=1; i<=rowIndex; i++) {
            ans[i] = 1;
            for(int j=i-1; j>0; j--)
                ans[j] += ans[j-1];
            ans[0] = 1;
        }
        return ans;
    }
};

static const auto speedupio=[]{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
