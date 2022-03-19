class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> newNums {nums.begin(), nums.end()};
        return nums.size() > newNums.size();
    }
};
