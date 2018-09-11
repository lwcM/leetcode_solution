static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0, r=nums.size(), lb=-1, ub=-1;
        while(l<r) {
            int m=(l+r)/2;
            if(nums[m] == target) {
                r = m;
                lb = m;
            }
            else if(nums[m] < target)
                l = m + 1;
            else
                r = m;
        }
        l = 0, r=nums.size();
        while(l<r) {
            int m=(l+r)/2;
            if(nums[m] == target) {
                l = m+1;
                ub = m;
            }
            else if(nums[m] < target)
                l = m + 1;
            else
                r = m;
        }
        return {lb, ub};
    }
};
