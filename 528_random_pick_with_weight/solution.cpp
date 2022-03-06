class Solution {
public:
    Solution(vector<int>& w) {
        for(int i : w){
            if(s.empty()) s.push_back(i);
            else s.push_back(i + s.back());
        }
    }
    
    int pickIndex() {
        int x = s.back();
        int idx = rand() % x;
        auto it = upper_bound(s.begin(), s.end(), idx);
        return it - s.begin();
    }
private:
    vector<int> s;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
