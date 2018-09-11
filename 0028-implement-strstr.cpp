static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        //KMP
        vector<int> failure;
        build_failure(failure, needle);
        int k=0;
        for(int i=0; i<haystack.size(); i++) {
            while(k >= 0 && haystack[i] != needle[k]) 
                k = failure[k];
            if(k == -1 || haystack[i] == needle[k]) k++;
            if(k == needle.size()) return i-k+1;
        }
        return -1;
    }
private:
    void build_failure(vector<int> &f, string &p) {
        f.push_back(-1);
        int k;
        for(int i=1; i<p.size(); i++) {
            int k = f[i-1];
            while (k >= 0 && p[i-1] != p[k])
                k = f[k];
            f.push_back(k+1);
        }
    }
};
