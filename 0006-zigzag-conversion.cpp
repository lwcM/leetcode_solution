static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        string ans="";
        for(int i=0; i<numRows; i++){
            for(int j=i; j<s.size(); j+=2*numRows-2) {
                ans += s[j];
                if(i && i != numRows-1 && j+2*numRows-2-2*i < s.size())
                    ans += s[j+2*numRows-2-2*i];
            }
        }
        return ans;
    }
};
