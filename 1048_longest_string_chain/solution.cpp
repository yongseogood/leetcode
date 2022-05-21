class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), compare);
        
        int res = 0;
        
        unordered_map<string, int> dp;

        for(const string& w : words) {
            for(int i = 0; i < w.length(); ++i) {
                string pre = w.substr(0, i) + w.substr(i + 1);
                dp[w] = max(dp[w], dp.find(w) == dp.end() ? 1 : dp[pre] + 1);
            }
            
            res = max(dp[w], res);
        }
        
        return res;
    }
private:
    static bool compare(const string& s1, const string& s2){
        return s1.length() < s2.length();
    }
};
