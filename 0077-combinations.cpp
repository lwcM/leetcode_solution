class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector <int> tmp;
        dfs(1, k, n, ans, tmp);
        return ans;
    }
private:
    void dfs(int i, int k, int &n, vector<vector<int>> &ans, vector<int> &arr) {
        if(!k) {
            ans.push_back(arr);
            return;
        }
        for(; i<=n && i<=n-k+1; i++) {
            arr.emplace_back(i);
            dfs(i+1, k-1, n, ans, arr);
            arr.pop_back();
        }
        
    }
};

static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
