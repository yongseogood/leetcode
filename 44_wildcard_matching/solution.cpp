class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        int i = 0, j = 0, ast = -1, match;
        
        while(i < m) {
            if(j < n && p[j] == '*') {
                match = i;
                ast = j++;
            } else if (j < n && (s[i] == p[j] || p[j] == '?')) {
                ++i, ++j;
            } else if (ast >= 0) {
                i = ++match;
                j = ast + 1;
            } else return false;
        }
        while(j < n && p[j] == '*') ++j;
        return j == n;
    }
};
