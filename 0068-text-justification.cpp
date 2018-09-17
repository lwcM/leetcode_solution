class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int used=0;
        for(int i=0; i<words.size(); i+=used) {
            int len=0, k;
            for(used=0; i+used<words.size() && len+used+words[i+used].size()<=maxWidth; used++)
                len += words[i+used].size();
            string s = words[i];
            for(int j=0; j<used-1; j++) {
                if(i+used >= words.size()) //lastline
                    s += ' ';
                else {
                    s += string((maxWidth-len)/(used-1),' ');
                    if(j < (maxWidth-len)%(used-1))
                        s += ' ';
                }
                s += words[i+j+1];
            }
            s += string(maxWidth-s.size(), ' ');
            ans.push_back(s);
        }
        return ans;
    }
};

static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
