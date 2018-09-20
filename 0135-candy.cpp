class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size()==0) return 0;
        int ans=1, inc=1, dec=1;
        for(int i=1; i<ratings.size(); i++) {
            if(ratings[i] >= ratings[i-1]) {
                if(dec > 1) { 
                    ans += dec*(dec-1)/2+max(dec-inc, 0);
                    dec = inc = 1;
                }
                if(ratings[i] > ratings[i-1])
                    ans += ++inc;
                else
                    inc = dec = 1, ans++;
            }
            else if(ratings[i] < ratings[i-1]) {
                dec++;
            }
        }
        if(dec > 1)
            ans += dec*(dec-1)/2+max(dec-inc, 0);
        return ans;
    }
};
static const auto speedupio=[]{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
