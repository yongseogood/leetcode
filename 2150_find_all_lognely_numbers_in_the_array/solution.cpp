class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> m;
        
        for(int num : nums) {
            m[num]++;
        }
        
        for(auto [n, cnt] : m)
            if(cnt == 1 && m.count(n - 1) == 0 && m.count(n + 1) == 0) res.push_back(n);
        
        return res;
    }
};
