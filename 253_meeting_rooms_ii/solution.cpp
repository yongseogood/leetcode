class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> datas;
        
        for(auto & in : intervals){
            datas[in[0]]++;
            datas[in[1]]--;
        }
        
        int cur = 0, res = 0;
        
        for(auto & data : datas)
        {
            cur += data.second;
            res = max(cur, res);
        }
        
        return res;
    }
};
