class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        vector <int> h(matrix[0].size()+1, 0);
        int ans = 0;
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                if(matrix[i][j] == '1')
                    h[j]++;
                else
                    h[j] = 0;
            }
            ans = max(ans, largestRectangleArea(h));
        }
        return ans;
    }
    
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
