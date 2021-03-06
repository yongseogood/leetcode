class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;

        for(int i = 0; i < target; ++i) {
            for(int j = 0; j < nums.size(); ++j) {
                if(nums[j] + i <= target) dp[nums[j] + i] += dp[i];
            }
        }
        
        return dp[target];
    }
};
