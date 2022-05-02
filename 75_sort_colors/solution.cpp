class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, l = 0, h = nums.size() - 1;
        
        while(i <= h) {
            if(nums[i] < 1) swap(nums[l++], nums[i++]);
            else if(nums[i] > 1) swap(nums[i], nums[h--]);
            else ++i;
        }
    }
};
