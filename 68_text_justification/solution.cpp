class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        for(int i = 0, k, l; i < words.size(); i += k) {
            for(k=l=0; i + k < words.size() && l + words[i + k].size() <= maxWidth - k; ++k) {
                l += words[i+k].size();
            }
                    
            string tmp = words[i];
        
            for(int j = 0; j < k - 1; ++j) {
                if(i + k >= words.size()) tmp += " ";
                else tmp += string((maxWidth - l) / (k - 1) + (j < (maxWidth - l) % (k - 1)), ' ');
                tmp += words[i + j + 1];
            }
            
            tmp += string(maxWidth - tmp.size(), ' ');
            res.push_back(tmp);
        }

        return res;
    }
};
