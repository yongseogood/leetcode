class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for(auto i : nums) ++counts[i];
        
        vector<vector<int>> b(nums.size() + 1);
        
        for(auto & k : counts)
            b[k.second].push_back(k.first);
        
        reverse(b.begin(), b.end());
        
        vector<int> res;
        
        for(auto & i : b) {
            for(auto j : i) {
                res.push_back(j);
                if(res.size() == k) return res;
            }
        }
        
        return res;
    }
};
