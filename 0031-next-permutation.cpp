static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<2) return;
        int i=nums.size()-2;
        while(i >= 0 && nums[i]>=nums[i+1]) i--;
        if(i < 0) {
            reverse(0, nums);
            return;
        }
        int j=i+1;
        while(j<nums.size() && nums[j]>nums[i]) j++;
        j--;
        swap(nums[i], nums[j]);
        reverse(i+1, nums);
    }
private:
    void reverse(int x, vector<int>& nums) {
        int sz = nums.size();
        for(int i=x; i<(x+sz)/2; i++)
            swap(nums[i], nums[sz-i-1+x]);
    }
};
