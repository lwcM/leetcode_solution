class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int cnt=1, len=1, num=nums[0];
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] == num) {
                if(cnt == 2)
                    continue;
                cnt++;
                nums[len++] = num;
            }
            else {
                cnt = 1;
                num = nums[i];
                nums[len++] = num;
            }
        }
        return len;
    }
};

static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
