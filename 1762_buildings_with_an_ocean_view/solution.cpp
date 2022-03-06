class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> res;
        for(int i = heights.size() - 1; i >=0; --i) {
            if(res.empty() || heights[i] > heights[res.back()]) {
                res.push_back(i);
            }
        }
        
        return vector<int>(res.rbegin(), res.rend());
    }
};
