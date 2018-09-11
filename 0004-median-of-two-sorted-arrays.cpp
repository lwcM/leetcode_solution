static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int find_k(vector<int>& nums1, vector<int>& nums2, int k) {
        int l1=0, r1=nums1.size();
        int l2=0, r2=nums2.size();
        while(k > 1 && l1<r1 && l2<r2) {
            int i1 = l1 + min(r1-l1, k>>1);
            int i2 = l2 + min(r2-l2, k>>1);
            if (nums1[i1 - 1] < nums2[i2 - 1]) {
                k -= i1 - l1;
                l1 = i1;
            }
            else {
                k -= i2 - l2;
                l2 = i2;
            }
        }
        if (l1 == r1)
            return nums2[l2 + k - 1];
        if (l2 == r2)
            return nums1[l1 + k - 1];
        return min(nums1[l1], nums2[l2]);
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sz=nums1.size()+nums2.size();
        return ((double)find_k(nums1, nums2, (sz+1)/2)+find_k(nums1, nums2, (sz+2)/2))/2;
    }
};
