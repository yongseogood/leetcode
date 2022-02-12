class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n, res = 0;
        grid.size() ? n = grid[0].size() : n = 0;
        
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == '1')
                {
                    res++;
                    eraseGrid(grid, i, j);
                }
            }
        }
            
        return res;
    }

private:
    void eraseGrid(vector<vector<char>>& grid, int i, int j)
    {
        int m = grid.size(), n = grid[0].size();
        
        if(i < 0 || i > (m - 1) || j < 0 || j > (n - 1) || grid[i][j] == '0') return;
        
        grid[i][j] = '0';
        
        eraseGrid(grid, i - 1, j);
        eraseGrid(grid, i + 1, j);
        eraseGrid(grid, i, j - 1);
        eraseGrid(grid, i, j + 1);
    }
};
