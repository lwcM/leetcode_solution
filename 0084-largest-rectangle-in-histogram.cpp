class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack <int> stk;
        int ans = 0;
        heights.push_back(0);
        for(int i=0; i<heights.size(); i++) {
            while(!stk.empty() && heights[stk.top()]>=heights[i]) {
                int idx = stk.top();
                stk.pop();
                ans = max(ans, (i-(stk.empty() ? -1:stk.top())-1)*heights[idx]);
            }
            stk.push(i);
        }
        return ans;
    }
};

static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
