class Solution {
public:
    bool validPalindrome(string s) {
        for(int i = 0, j = s.size() - 1; i < j; ++i, --j)
            if(s[i] != s[j]) return isP(s, i + 1, j) || isP(s, i, j - 1);        
        return true;
    }

private:
    bool isP(string s, int i, int j) {
        for(; i < j; ++i, --j)
            if(s[i] != s[j]) return false;
        
        return true;
    }
};
