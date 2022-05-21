class Solution {
public:
    bool isHappy(int n) {
        vector<int> hash;
        
        while(n != 1) {
            if(find(hash.begin(), hash.end(), n) == hash.end()) hash.push_back(n);
            else return false;
            
            int sum = 0;
            
            while(n != 0) {
                sum += pow(n % 10, 2);
                n /= 10;
            }
            
            n = sum;
        }
        
        return true;
    }
};
