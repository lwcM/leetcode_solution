class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector <int> tmp;
        dfs(0, nums, ans, tmp);
        return ans;
    }
private:
    void dfs(int k, vector<int>& nums, vector<vector<int>> &ans, vector<int> &arr) {
        if(k==nums.size()) {
            ans.push_back(arr);
            return;
        }
        arr.emplace_back(nums[k]);
        dfs(k+1, nums, ans, arr);
        arr.pop_back();
        dfs(k+1, nums, ans, arr);
        
    }
};

static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
