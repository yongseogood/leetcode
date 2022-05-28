class Solution {
public:
    int racecar(int target) {
        queue<vector<int>> q;
        q.push({0, 0, 1});
        
        while(!q.empty()) {
            vector<int> item = q.front();
            q.pop();
            
            int moves = item[0];
            int pos = item[1];
            int speed = item[2];
            
            if(pos == target) return moves;
            
            if(abs(pos) > 2 * target) continue;
            
            q.push({moves + 1, pos + speed, 2 * speed});
            
            if((pos + speed > target && speed > 0) || (pos + speed < target && speed < 0)) {
                q.push({moves + 1, pos, (speed > 0) ? -1 : 1});
            }
        }
        
        return 0;
    }
};
