class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
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
        for(int i=k; i<nums.size(); i++) {
            if(i == k || nums[i] != nums[i-1]) {
                arr.emplace_back(nums[i]);
                dfs(i+1, nums, ans, arr);
                arr.pop_back();
            }
        }
        dfs(nums.size(), nums, ans, arr);
    }
};

static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
