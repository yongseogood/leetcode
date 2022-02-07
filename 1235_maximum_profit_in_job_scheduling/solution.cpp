class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        
        for(int i = 0; i < startTime.size(); ++i) {
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end());
        
        map<int, int> res = {{0, 0}};
        
        for(auto & job : jobs) {
            int cur = prev(res.upper_bound(job[1]))->second + job[2];
            
            if(cur > res.rbegin()->second) res[job[0]] = cur;
        }
        
        return res.rbegin()->second;
    }
};
