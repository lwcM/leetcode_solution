static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> v;
        for(int i=0; i<nums.size(); i++) {
            if(i && nums[i-1]==nums[i]) continue;
            for(int j=i+1; j<nums.size(); j++) {
                if(j>i+1 && nums[j-1]==nums[j]) continue;
                int l=j+1, r=nums.size()-1;
                while(l<r) {
                    int s = nums[i]+nums[j]+nums[l]+nums[r];
                    if(s < target) l++;
                    else if(s > target) r--;
                    else {
                        v.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while(l < r && nums[l] == nums[l+1]) l++;
                        while(l < r && nums[r] == nums[r-1]) r--;
                        l++;
                        r--;
                    }
                }
            }
        }
        return v;
    }
};
