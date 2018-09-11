static const auto speedupio=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int myAtoi(string str) {
        int i=0, neg=1;
        while(i<str.size() && str[i] == ' ') i++;
        if(str[i] == '-' || str[i] == '+'){
            neg=2*(str[i]=='+')-1;
            i++;
        }
        long long sum=0;
        for(; i<str.size(); i++) {
            if(!isdigit(str[i])) break;
            sum=sum*10+(str[i]-'0');
            if(sum*neg>INT_MAX) return INT_MAX;
            if(sum*neg<INT_MIN) return INT_MIN;
        }
        return (int)(neg*sum);
    }
};
