/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if(intervals.size()==0) return vector<Interval>(1, newInterval);
        
        int i;
        for(i=0; i<intervals.size(); i++)
            if(newInterval.start < intervals[i].start || (newInterval.start == intervals[i].start && newInterval.end <= intervals[i].end))
                break;
        intervals.insert(intervals.begin()+i, newInterval);
        
        vector<Interval> ans;
        int x=intervals[0].start, y=intervals[0].end;
        for(int i=1; i<intervals.size(); i++) {
            if(intervals[i].start <= y)
                y = max(y, intervals[i].end);
            else {
                ans.push_back(Interval(x, y));
                x = intervals[i].start;
                y = intervals[i].end;
            }
                
        }
        ans.push_back(Interval(x, y));
        return ans;
    }
};

static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
