class Solution {
public:
    bool isNumber(string s) {
        while(s.size() && s[0] == ' ') s.erase(0, 1);
        while(s.size() && s[s.size()-1] == ' ') s.erase(s.size()-1, 1);
        if(s.size() == 0) return false;
        int i=0;
        if(i < s.size() && (s[i] == '+' || s[i] == '-')) i++;
        
        bool hasdigit1 = false;
        while(i < s.size() && isdigit(s[i])) i++, hasdigit1=true;
        
        if(i < s.size() && !hasdigit1 && s[i] != '.') return false;
        //if(!hasdigits(i, s)) return false;

        if(i < s.size() && s[i] == '.') {
            i++;
            bool hasdigit2 = false;
            while(i < s.size() && isdigit(s[i])) i++, hasdigit2=true;
            if(i < s.size() && !hasdigit2 && s[i] != 'e') return false;
            if(!hasdigit1 && !hasdigit2) return false;
        }
        if(i < s.size() && s[i] == 'e') {
            i++;
            if(i < s.size() &&  (s[i] == '+' || s[i] == '-')) i++;    
            if(!hasdigits(i, s)) return false;
        }
        return i == s.size();
    }
    
    bool hasdigits(int &i, string &s) {
        bool hasdigit = false;
        while(i < s.size() && isdigit(s[i])) i++, hasdigit=true;
        if(!hasdigit) return false;
        return true;
    }
};

static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
