class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        multiset<vector<int>, compare> mset (points.begin(), points.end());
        
        vector<vector<int>> res;
        copy_n(mset.begin(), k, back_inserter(res));
        return res;
    }
private:
    struct compare {
        bool operator()(const vector<int>&p, const vector<int>& q) const {
            return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
        }
    };
};
