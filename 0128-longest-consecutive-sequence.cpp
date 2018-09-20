class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0;
        for(int x:nums) {
            if(mp.find(x) == mp.end()) {
                int left = (mp.find(x-1) != mp.end() ? mp[x-1]:0);
                int right = (mp.find(x+1) != mp.end() ? mp[x+1]:0);
                int sum = left+right+1;
                mp[x] = mp[x-left] = mp[x+right] = sum;
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};

static const auto speedupio=[]{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
