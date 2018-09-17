class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int ans=nums[0], sum=0;
        for(int x:nums) {
            ans = max(ans, sum+=x);
            if(sum < 0) sum = 0;
        }
        return ans;
    }
};


static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
