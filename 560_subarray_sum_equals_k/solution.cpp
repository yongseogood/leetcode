class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, res = 0;
        
        unordered_map<int, int> hash;
        
        hash[0]++;
        
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i]; 
            if(hash[sum-k]) res+= hash[sum -k]; 
            hash[sum]++;
                
        }
        
        return res;
    }
};
