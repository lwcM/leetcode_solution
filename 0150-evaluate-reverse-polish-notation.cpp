class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector <int> stk;
        for(auto s:tokens) {
            if(s == "+") stk[stk.size()-2] += stk[stk.size()-1];
            else if(s == "-") stk[stk.size()-2] -= stk[stk.size()-1];
            else if(s == "*") stk[stk.size()-2] *= stk[stk.size()-1];
            else if(s == "/") stk[stk.size()-2] /= stk[stk.size()-1];
            else {
                stk.push_back(stoi(s));
                continue;
            }
            stk.pop_back();
        }
        return stk[0];
    }
};

static const auto speedupio=[]{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
