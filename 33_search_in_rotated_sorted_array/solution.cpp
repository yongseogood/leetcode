class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;
        
        while(l <= h) {
            int m = (l + h) / 2;
            
            if(nums[m] == target) return m;
            
            if(nums[m] > nums[h]) {
                if(target < nums[m] && target >= nums[l]) h = m - 1;
                else l = m + 1;
            } else if(nums[m] < nums[h]) {
                if(target > nums[m] && target <= nums[h]) l = m + 1;
                else h = m -1;
            } else {
                if(target > nums[m]) l = m + 1;
                else h = m - 1;
            }
        }

        return -1;
    }
};
