class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, h = nums.size() - 1, m;
        
        while(l < h) {
            m = (l + h) / 2;
            if(nums[m] < nums[m + 1]) l = m + 1;
            else h = m;
        }
        
        return l;
    }
};
