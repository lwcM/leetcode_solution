/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int n=points.size(), ans=0;
        for(int i=0; i<n; i++) {
            unordered_map<int, unordered_map<int, int>> mp;
            int same=0, mn=0;
            for(int j=i+1; j<n; j++) {
                int dx = points[i].x-points[j].x;
                int dy = points[i].y-points[j].y;
                if(dx == 0 && dy == 0) {
                    same++;
                }
                else {
                    int g = gcd(dx, dy);
                    mn = max(mn, ++mp[dx/g][dy/g]);
                }
            }
            ans = max(ans, mn+same+1);
        }
        return ans;
    }
    
    int gcd(int a, int b) {
        if(b == 0) return a;
        return gcd(b, a%b);
    }
};

static const auto speedupio=[]{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
