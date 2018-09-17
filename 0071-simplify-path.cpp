class Solution {
public:
    string simplifyPath(string path) {
        if(path.size() == 0 || path[0] != '/') return path;
        string ans="";
        int pos=1;
        if(path[path.size()-1] != '/')
            path += '/';
        while(pos < path.size()) {
            int pos2=pos;
            while(path[pos2] != '/') pos2++;
            string tmp = path.substr(pos, pos2-pos);
            if(tmp == "..")
                move_to_parent(ans);
            else if(tmp != "." && tmp != "")
                ans += "/" + tmp;
            pos = pos2+1;
        }
        if(ans == "") ans = "/";
        return ans;
    }
    
    void move_to_parent(string &path) {
        int pos=path.size()-1;
        while(pos>0 && path[pos] != '/') pos--;
        if(pos >= 0) path.erase(pos);
    }
};

static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
