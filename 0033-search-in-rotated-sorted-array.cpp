static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        int l=0, r=nums.size();
        while(l < r) {
            int m=(l+r)/2;
            if(nums[m] >= nums[l] && nums[m] >= nums[0])
                l = m+1;
            else
                r = m;
        }
        if(target >= nums[0])
            r = l, l = 0;
        else
            r = nums.size();
        while(l < r) {
            int m=(l+r)/2;
            if(nums[m] == target)
                return m;
            else if(nums[m] < target)
                l = m+1;
            else
                r = m;
        }
        return -1;
    }
};
