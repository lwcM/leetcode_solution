class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int first=0, second=0;
        for(int &x:nums) {
            first = first ^ x & ~second;
            second = second ^ x & ~first;
        }
        return first;
    }
};

static const auto speedupio=[]{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
