static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    string multiply(string num1, string num2) {
        int *ans = new int[num1.size()+num2.size()](), sz=num1.size()+num2.size();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for(int i=0; i<num1.size(); i++)
            for(int j=0; j<num2.size(); j++)
                ans[i+j] = ans[i+j]+(num1[i]-'0')*(num2[j]-'0');
        for(int i=0; i<sz; i++) {
            if(ans[i] >= 10) {
                ans[i+1] += (ans[i])/10;
                ans[i] = (ans[i])%10;
            }
        }
        int tail=sz-1;
        while(tail>0 && ans[tail] == 0) tail--;
        string ret = "";
        while(tail>=0)
            ret += ans[tail--]+'0';
        delete [] ans;
        return ret;
    }
};
