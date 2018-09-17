class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero=0, two=nums.size()-1;
        for(int i=0; i<=two; ) {
            while(i<=two && nums[i] == 2)
                swap(nums[i], nums[two--]);
            while(nums[zero]==0)
                zero++;
            if(i<zero) i=zero;
            while(zero<=two && nums[i]==0)
                swap(nums[i], nums[zero++]);
            if(nums[i]==1)
                i++;
        }
    }
};

static const auto __=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
