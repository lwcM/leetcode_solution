static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    string intToRoman(int num) {
        int d[7] = {1000, 500, 100, 50, 10, 5, 1};
        int x[7] = {1000, 100, 100, 10, 10, 1, 1};
        unordered_map <int, char> mp = {{1000, 'M'},{500, 'D'},{100, 'C'},{50, 'L'},{10, 'X'},{5, 'V'},{1, 'I'}};
        string ans="";
        for(int i=0; i<7; i++) {
            if(!(i & 1) && num / d[i]) {
                while(num >= d[i]) {
                    num-=d[i];
                    ans += mp[d[i]];
                }
            }
            else if(num/x[i] == 9) {
                ans = ans + mp[d[i+1]] + mp[d[i-1]];
                num -= 9 * x[i];
            }
            else if(num/x[i] == 4) {
                ans = ans + mp[d[i+1]] + mp[d[i]];
                num -= 4 * x[i];
            }
            else if(num / d[i]) {
                ans += mp[d[i]];
                num -= d[i];
            }
        }
        return ans;
    }
};

