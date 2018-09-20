class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(gas.size() == 0) return -1;
        int l=0, r=0, gs=gas[0], n=gas.size(), move=0;
        for(;move < n; move++) {
            if(gs-cost[r]>=0) {
                gs = gs-cost[r]+gas[(r+1)%n];
                r=(r+1)%n;
            }
            else {
                l = (l-1+n)%n;
                gs = gs-cost[l]+gas[l];
            }
        }
        if(gs-gas[l] >= 0)
            return l;
        return -1;
        
    }
};

static const auto speedupio=[]{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
