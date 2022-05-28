class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        long long m = points.size(), n = points[0].size();
        
        vector<long long> pre(n);
        
        for(int i = 0; i < n; ++i) pre[i] = points[0][i];
        
        for(int i = 0; i < m - 1; ++i) {
            vector<long long> l(n, 0), r(n, 0), cur(n, 0);
            l[0] = pre[0];
            r[n - 1] = pre[n - 1];
            
            for(int j = 1; j < n; ++j)
                l[j] = max(l[j - 1] - 1, pre[j]);
            
            for(int j = n - 2; j >=0; --j)
                r[j] = max(r[j + 1] - 1, pre[j]);
                
            for(int j = 0; j < n; ++j)
                cur[j] = points[i + 1][j] + max(l[j], r[j]);
                
            pre = cur;
        }
                
        long long res = 0;
                
        for(int i = 0; i < n; ++i)
            res = max(res, pre[i]);
        
        return res;
    }
};
