bool comp(vector<int> &a, vector<int> &b) {
    return a[1] < b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int res = -1;
        
        if(intervals.size() == 0) return 0;
        
        sort(intervals.begin(), intervals.end(), comp);
        
        vector<int> prev = intervals[0];
        
        for(auto &i : intervals) {
            if(prev[1] > i[0]) {
                ++res;
            } else
                prev = i;
        }
        return res;
    }
};
