class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minMo = 0, minEle = *min_element(nums.begin(), nums.end());
        
        for(int e : nums)
            minMo += e - minEle;
        
        return minMo;
    }
};
