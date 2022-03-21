class WordDistance {
public:
    WordDistance(vector<string>& wordsDict) {
        for(int i = 0; i < wordsDict.size(); ++i) {
            map_[wordsDict[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int res = INT_MAX;
        
        for(int i = 0, j = 0; i < map_[word1].size() && j < map_[word2].size();) {
            res = min(res, abs(map_[word1][i] - map_[word2][j]));
            if(map_[word1][i] < map_[word2][j]) ++i;
            else ++j;
        }
        
        return res;
    }
private:
    unordered_map<string, vector<int>> map_;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
