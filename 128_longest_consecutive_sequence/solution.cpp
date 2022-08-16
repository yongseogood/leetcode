class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        int res = 0;
        for(int n : nums) {
            if(m[n]) continue;
            
            if(m.find(n - 1) == m.end() && m.find(n + 1) == m.end()) {
                res = max(res, m[n] = 1);
                continue;
            }
            
            if(m.find(n - 1) == m.end()) {
                int r = m[n] = m[n+m[n + 1]] = m[n + 1] + 1;
                res = max(res, r);
                continue;
            }
            
            if(m.find(n + 1) == m.end()) {
                int r = m[n] = m[n - m[n - 1]] = m[n - 1] + 1;
                res = max(res, r);
                continue;
            }
            
            int r = m[n - m[n - 1]] = m[n + m[n + 1]] = 1 + m[n + 1] + m[n - 1];
            m[n] = 1;
            
            res = max(res, r);
        }
        
        return res;
    }
};
