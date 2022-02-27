class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            
            int l = i + 1, r = nums.size() - 1;
            
            while(l < r) {
                int t = nums[i] + nums[l] + nums[r];
                
                if(t > 0) --r;
                else if(t < 0) ++l;
                else {
                    vector<int> tmp = {nums[i], nums[l], nums[r]};
                    res.push_back(tmp);
                    while(l + 1 < r && nums[l]==nums[l+1]) ++l;
                    while(r - 1 > l && nums[r]==nums[r-1]) --r;
                    --r, ++l;
                }
            }
        }
        return res;
    }
};
