class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int x:nums)
            ans ^= x;
        return ans;
    }
};

static const auto speedupio=[]{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
