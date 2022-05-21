class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int res = 24 * 60;
        
        vector<int> tt;
        
        for(int i = 0; i < timePoints.size(); ++i) {
            int t = stoi(timePoints[i].substr(0, 2)) * 60 + stoi(timePoints[i].substr(3, 2));
            tt.push_back(t);
        }
        
        sort(tt.begin(), tt.end());
        tt.push_back(tt[0] + res);
        
        for(int i = 1; i < tt.size(); ++i) {
            res = min(res, tt[i] - tt[i - 1]);
        }
        
        return res;
    }
};
