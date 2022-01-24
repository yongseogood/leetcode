class Solution {
public:
    bool detectCapitalUse(string word) {
        bool allCap {true};
        for(int i = 0; i < word.size(); ++i)
        {
            if(islower(word[i]))
                allCap = false;
        }
        
        if(allCap) return true;

        for(int i = 1; i < word.size(); ++i)
        {
            if((isupper(word[0]) && isupper(word[i])) || (islower(word[0]) && isupper(word[i])))
                return false;
        }
        
        return true;
    }
};
