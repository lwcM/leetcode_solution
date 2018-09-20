class LRUCache {
public:
    list <pair<int, int>> l;
    unordered_map <int, list <pair<int, int>>::iterator> mp;
    int cap;
    
    LRUCache(int capacity) {
        l.clear();
        mp.clear();
        cap = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            auto &x = mp[key];
            if(x != l.begin())
                l.splice(l.begin(), l, x, next(x));
            return (*x).second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            auto &x = mp[key];
            if(x != l.begin())
                l.splice(l.begin(), l, x, next(x));
            (*x).second = value;
        }
        else {
            if(l.size() >= cap) {
                mp.erase(l.back().first);
                l.pop_back();
            }
            l.push_front(make_pair(key, value));
            mp[key] = l.begin();
        }
    }
};

static const auto speedupio=[]{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
