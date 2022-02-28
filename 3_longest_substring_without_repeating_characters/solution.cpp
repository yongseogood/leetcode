class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;

        vector<int> hash(256,-1);
        int res = 1, cnt = - 1;
        
        for(int i = 0; i < s.size(); ++i) {
            cnt = max(cnt, hash[s[i]]);
            hash[s[i]] = i;
            res = max(res, i -cnt);
        }
        
        return res;
    }
};
