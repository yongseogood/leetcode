class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), b = 1, l = 1;
        
        vector<int> res(n,1);
        
        for(int i = 0; i < n; ++i) {
            res[i] *= b;
            b *= nums[i];
        }
        
        for(int i = n - 1; i >= 0; --i) {
            res[i] *= l;
            l *= nums[i];
        }
        
        return res;
    }
};
