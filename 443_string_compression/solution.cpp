class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> res;
        for(int i = 1, count = 1; i <= chars.size(); ++i, ++count) {
            if(i == chars.size() || chars[i] != chars[i - 1]) {
                res.push_back(chars[i - 1]);
                
                if(count >= 2)
                    for(char d : to_string(count))
                        res.push_back(d);
                count = 0;
            }
        }
        
        chars = res;
        return res.size();
    }
};
