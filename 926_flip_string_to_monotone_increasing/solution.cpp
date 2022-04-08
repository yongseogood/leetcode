class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int counter = 0, res = 0;
        
        for(auto ch : s) {
            if(ch == '1') {
                ++counter;
            } else {
                ++res;
            }
            
            res = min(counter, res);
        }
        
        return res;
    }
};
