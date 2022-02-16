class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> res;
        
        for(int num : nums) {
            res.insert(num);
            
            if(res.size() > k) res.erase(res.begin());
        }
        
        return *res.begin();
    }
};
