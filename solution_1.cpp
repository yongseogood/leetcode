class Solution {
public:
    int getSum(int a, int b) {
        int res = 0;
        
        while(a != 0) {
            if(a > 0) res++, a--;
            else res--, a++;
        }
        while(b != 0) {
            if(b > 0) res++, b--;
            else res--, b++;
        }
        return res;
    }
};
