class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0) return false;
        int l=0, r=nums.size();
        while(l<r) {
            int m=(l+r)/2;
            if(nums[m]==target) return true;
            if(nums[m]>nums[l]) {
                if(target >= nums[l] && target < nums[m])
                    r = m;
                else
                    l = m+1;
            }
            else if(nums[m]<nums[l]) {
                if(target > nums[m] && target <= nums[r-1])
                    l = m+1;
                else
                    r = m;
            }
            else
                l++;
        }
        return false;
    }
};

static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
