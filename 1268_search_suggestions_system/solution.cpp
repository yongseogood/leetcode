class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        auto it = products.begin();

        vector<vector<string>> res;
        
        string cur = "";
        
        for(char c : searchWord) {
            cur += c;
            
            vector<string> tmp;
            
            it = lower_bound(it, products.end(), cur);
                       
            for(int i = 0; i < 3 && it + i != products.end(); ++i) {
                string s = *(it + i);
                if(s.find(cur)) break;
                
                tmp.push_back(s);
            }
            
            res.push_back(tmp);
        }
        
        return res;
    }
};
