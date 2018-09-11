static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> v;
        int mn=INT_MAX, ans;
        for(int i=0; i<nums.size(); i++) {
            if(i && nums[i-1]==nums[i]) continue;
            int l=i+1, r=nums.size()-1;
            while(l<r) {
                int s = nums[i]+nums[l]+nums[r];
                if(s == target) return s;
                if(mn>abs(s-target)) {
                    mn = abs(s-target);
                    ans = s;
                }
                if(s < target) l++;
                else r--;
            }
        }
        return ans;
    }
};
