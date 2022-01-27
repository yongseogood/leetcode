class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        else if(nums.size() == 1) return nums[0];
        
        int result = nums[0], currMax = nums[0];
        
        for(int i = 1; i < nums.size(); ++i)
        {
            currMax = std::max(currMax + nums[i], nums[i]);
            result = std::max(result, currMax);
        }
        
        return result;
    }
};
