class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        if(m == 0) return 0;
        
        int n = board[0].size(), cnt = 0;
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(board[i][j] == '.') continue;
                else if(i > 0 && board[i - 1][j] == 'X') continue;
                else if(j > 0 && board[i][j - 1] == 'X') continue;
                ++cnt;
            }
        }
        
        return cnt;
    }
};
