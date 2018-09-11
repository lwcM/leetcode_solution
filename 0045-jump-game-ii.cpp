static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int ans=0, l=0, r=0;
        while(nums.size()-1 > r) {
            int mx=0;
            for(int i=l; i<=r && i < nums.size(); i++)
                mx = max(mx, i+nums[i]);
            l=r+1, r=mx;
            ans++;
        }
        return ans;
    }
};
