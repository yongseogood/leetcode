class Solution {
public:
    int minAddToMakeValid(string s) {
        int l = 0, r = 0;
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == '(') ++r;
            else {
                if(r > 0) --r;
                else ++l;
            }
        }
        
        return l + r;
    }
};
