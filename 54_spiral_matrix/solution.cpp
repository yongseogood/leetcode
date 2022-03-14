class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<int>> dirs {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> res;
        
        int nr = matrix.size(); if(nr == 0) return res;
        int nc = matrix[0].size(); if(nc == 0) return res;

        vector<int> steps {nc, nr - 1};

        int idx = 0;
        int ir = 0, ic = -1;

        while(steps[idx % 2]) {
            for(int i = 0; i < steps[idx % 2]; ++i) {
                ir += dirs[idx][0]; ic += dirs[idx][1];
                res.push_back(matrix[ir][ic]);
            }

            steps[idx % 2]--;
            idx = (idx + 1) % 4;
        }
        
        return res;
        
    }
};
