static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        dfs(0, nums, ans);
        return ans;
    }
private:
    void dfs(int k, vector<int>& nums, vector<vector<int>> &ans) {
        if(k == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for(int i=k; i<nums.size(); i++) {
            swap(nums[i], nums[k]);
            dfs(k+1, nums, ans);
            swap(nums[i], nums[k]);
        }
    }
};
