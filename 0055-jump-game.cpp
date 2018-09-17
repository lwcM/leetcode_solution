class Solution {
public:
    bool canJump(vector<int>& nums) {
        int l=0, r=0;
        while(l<=r) {
            int mx=0;
            for(int i=l; i<=r; i++)
                mx = max(mx, i+nums[i]);
            l=r+1, r=mx;
            if(r >= nums.size()-1)
                return true;
        }
        return false;
    }
};
              
static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
