class Solution {
public:
    vector<int> grayCode(int n) {
        if(n == 0) return {0};
        vector<int> ans = {0, 1};
        for(int i=2; i<=n; i++) {
            int ll = ans.size();
            for(int j=ll-1; j>=0; j--)
                ans.push_back(ans[j]*2+1);
            for(int j=ll-1; j>=0; j--)
                ans[j] *= 2;
        }
        return ans;
    }
};

static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
