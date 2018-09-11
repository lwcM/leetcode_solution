static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int cnt=1, num=nums[0];
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] != num){
                nums[cnt++] = nums[i];
                num = nums[i];
            }
        }
        return cnt;
        
    }
};
