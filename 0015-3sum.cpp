static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> v;
        for(int i=0; i<nums.size(); i++) {
            if(i && nums[i-1]==nums[i]) continue;
            int l=i+1, r=nums.size()-1;
            while(l<r) {
                int s = nums[i]+nums[l]+nums[r];
                if(s < 0) l++;
                else if(s > 0) r--;
                else {
                    v.push_back({nums[i], nums[l], nums[r]});
                    while(l < r && nums[l] == nums[l+1]) l++;
                    while(l < r && nums[r] == nums[r-1]) r--;
                    l++;
                    r--;
                }
            }
        }
        return v;
    }
};
