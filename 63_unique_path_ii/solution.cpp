class Solution {
public:
    int numWays(int n, int k) {
        if(n == 0) return 0;
        else if(n == 1) return k;
        
        int diffColCnt = k * (k - 1);
        int sameColCnt = k;
        
        for(int i = 2; i < n; ++i) {
            int tmp = diffColCnt;
            diffColCnt = (diffColCnt + sameColCnt) * (k - 1);
            sameColCnt = tmp;
        }
        
        return diffColCnt + sameColCnt;
    }
};
