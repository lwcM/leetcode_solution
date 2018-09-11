static auto x = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    return 0;
}();
class Solution {
public:
    string longestPalindrome(string s) {
        string ss="^";
        if(s.size())
            ss += "#";
        for(int i=0; i<s.size(); i++)
            ss = ss+s[i]+'#';
        ss += "$";
        //Manacher’s Algorithm
        int p[2048]={0};
        int R=0, C=0;
        int ans=0, pos=0;
        for(int i=1; i+1<ss.size(); i++) {
            p[i] = R>i ? min(R-i, p[C*2-i]):0;
            while(ss[i+p[i]+1]==ss[i-p[i]-1])
                p[i]++;
            if(i+p[i] > R){
                R = i + p[i];
                C = i;
            }
            if(p[i] > ans) {
                ans = p[i];
                pos = i;
            }
        }
        return s.substr((pos-ans-1)/2, ans);
    }
};
