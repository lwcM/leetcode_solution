class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int i=0, j=0;
        for(; i<a.size()&&j<b.size(); i++, j++)
            ans += a[i]+b[j]-'0';
        while(i<a.size()) ans += a[i++];
        while(j<b.size()) ans += b[j++];
        for(int i=0; i<ans.size(); i++) {
            if(ans[i] >= '2') {
                ans[i] -= 2;
                if(i == ans.size()-1)
                    ans += '1';
                else
                    ans[i+1] ++;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
