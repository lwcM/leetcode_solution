static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector <int> used;
        vector<vector<int>> ans;
        dfs(0, 0, used, candidates, target, ans);
        return ans;
    }
    void dfs(int k, int sum, vector<int> &used, vector<int>& candidates, int &target, vector<vector<int>> &ans) {
        if(sum > target) return;
        if(sum == target) {
            ans.push_back(used);
            return;
        }
        for(int i=k; i<candidates.size(); i++) {
            if(i>k && candidates[i] == candidates[i-1])
                continue;
            if(sum + candidates[i] <= target) {
                used.push_back(candidates[i]);
                dfs(i+1, sum+candidates[i], used, candidates, target, ans);
                used.pop_back();
            }
        }
    }
};
