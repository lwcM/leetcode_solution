static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0, r=nums.size();
        while(l<r) {
            int m=(l+r)/2;
            if(nums[m]==target)
                return m;
            else if(nums[m]>target)
                r=m;
            else
                l=m+1;
        }
        return l;
    }
};
