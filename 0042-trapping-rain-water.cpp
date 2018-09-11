static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left_max(height);
        vector<int> right_max(height);
        int mx = 0;
        for(int i=0; i<height.size(); i++)
            left_max[i] = mx = max(height[i], mx);
        mx = 0;
        for(int i=height.size()-1; i>=0; i--)
            right_max[i] = mx = max(height[i], mx);
        int ans = 0;
        for(int i=0; i<height.size(); i++)
            if(height[i] <= left_max[i] && height[i] <= right_max[i])
                ans += min(left_max[i], right_max[i])-height[i];
        return ans;
    }
};
