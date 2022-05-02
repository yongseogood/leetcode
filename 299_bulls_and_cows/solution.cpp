class Solution {
public:
    string getHint(string secret, string guess) {
        int a = 0, b = 0;
        vector<int> s(10, 0);
        vector<int> g(10, 0);
        
        if(secret.size() != guess.size() || secret.empty()) { return "0A0B"; }
        
        for(int i = 0; i < secret.size(); ++i) {
            char c1 = secret[i];
            char c2 = guess[i];
            
            if(c1 == c2) {
                ++a;
            } else {
                ++s[c1 - '0'];
                ++g[c2 - '0'];
            }
        }
        
        for(int i = 0; i < s.size(); ++i) {
            b += min(s[i], g[i]);
        }
        
        return to_string(a) + 'A' + to_string(b) + 'B';
    }
};
