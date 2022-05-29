/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        for(int i = 0; i < 10; ++i) {
            string& guessW = wordlist[rand() % wordlist.size()];
            int guessM = master.guess(guessW);
            
            vector<string> newlist;
            
            for(string& word: wordlist) {
                if(guessM == myMatch(word, guessW)) {
                    newlist.push_back(word);
                }
            }
            
            wordlist = newlist;
        }  
    }

private:
    int myMatch(string& w1, string& w2) {
        int cnt = 0;
        
        for(int i = 0; i < 6; ++i) {
            if(w1[i] == w2[i]) {
                ++cnt;
            }
        }
        
        return cnt;
    }
};
