class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int res = 0;
        vector<int> p(60);
        
        for(int i = 0; i < time.size(); ++i) {
            int r = time[i] % 60;
            
            if(r == 0) res += p[0];
            else res += p[60 - r];
            
            p[r]++;
        }
        
        return res;
    }
};
