static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector <bool> visited(nums.size(), false);
        vector <int> tmp(nums);
        vector<vector<int>> ans;
        dfs(0, tmp, nums, visited, ans);
        return ans;
    }
private:
    void dfs(int k, vector<int>& tmp, vector<int>& nums, vector <bool> &visited, vector<vector<int>> &ans) {
        if(k == nums.size()) {
            ans.push_back(tmp);
            return;
        }
        for(int i=0; i<nums.size(); i++) {
            if(!visited[i] && (!i || visited[i-1] || nums[i] != nums[i-1])) {
                visited[i] = true;
                tmp[k] = nums[i];
                dfs(k+1, tmp, nums, visited, ans);
                visited[i] = false;
            }
        }
    }
};

