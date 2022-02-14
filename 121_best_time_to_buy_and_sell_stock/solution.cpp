class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = INT_MAX, res = 0, diff = 0;
        
        for(auto p : prices)
        {
            m = min(m, p);
            
            diff = p - m;
            
            res = max(diff, res);
        }
        
        return res;
    }
};
