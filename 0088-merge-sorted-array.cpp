class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int x=m+n-1, i=m-1, j=n-1;
        while(i>=0 && j>=0) {
            if(nums1[i] >= nums2[j])
                nums1[x--] = nums1[i--];
            else
                nums1[x--] = nums2[j--];
        }
        while(j>=0)
            nums1[x--] = nums2[j--];
    }
};

static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
