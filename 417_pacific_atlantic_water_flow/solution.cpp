class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if(heights.empty()) return res;
        int m = heights.size();
        int n = heights[0].size();
        
        visited.resize(m, vector<int>(n, 0));
        
        for(int j = 0; j < n; ++j){
            dfs(heights, 0, j, INT_MIN, 1);
            dfs(heights, m - 1, j, INT_MIN, 2);
        }
        
        for(int i = 0; i < m; ++i){
            dfs(heights, i, 0, INT_MIN, 1);
            dfs(heights, i, n - 1, INT_MIN, 2);
        }
        
        return res;
    }

private:
    vector<vector<int>> res;
    vector<vector<int>> visited;
    
    void dfs(vector<vector<int>>& h, int x, int y, int pre, int label) {
        if(x < 0 || x >= h.size() || y < 0 || y >= h[0].size() || h[x][y] < pre || visited[x][y] == 3 || visited[x][y] == label)
            return;
        
        visited[x][y] += label;
        
        if(visited[x][y] == 3) res.push_back({x, y});
        
        dfs(h, x + 1, y, h[x][y], label);
        dfs(h, x - 1, y, h[x][y], label);
        dfs(h, x, y + 1, h[x][y], label);
        dfs(h, x, y - 1, h[x][y], label);
    }
};
