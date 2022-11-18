class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() < 2) return res;
        
        sort(nums.begin(), nums.end());
        
        set<vector<int>> tmpRes;
        int n = nums.size();

        for(int i = 0; i < n - 2; ++i)
        {
            int l = i + 1, r = n - 1;
            int t = -nums[i];
            
            while(l < r)
            {
                int s = nums[l] + nums[r];
                
                if(s > t)
                    --r;
                else if (s < t)
                    ++l;
                else
                {
                    tmpRes.insert({nums[i], nums[l], nums[r]});
                    --r, ++l;
                }
            }
        }
        
        for(auto & r : tmpRes)
            res.push_back(r);
        
        return res;
    }
};
