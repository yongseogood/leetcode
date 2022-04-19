class Solution {
public:
    int climbStairs(int n) {
        if(n <= 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 2;
        
        int one = 2;
        int two = 1;
        int all = 0;
        
        for(int i = 2; i < n; ++i) {
            all = one + two;
            two = one;
            one = all;
        }
        
        return all;
    }
};
