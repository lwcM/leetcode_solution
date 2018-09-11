static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    bool isValid(string s) {
        stack <char> stk;
        unordered_map <char, char> mp = {{'}','{'}, {']','['}, {')','('}};
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                stk.push(s[i]);
            else if(stk.empty() || stk.top() != mp[s[i]])
                return false;
            else
                stk.pop();
        }
        return stk.empty();
    }
};
