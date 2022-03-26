class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses, vector<int>());
        queue<int> n;
        vector<int> d(numCourses, 0);
        int n_size = 0;
        
        vector<int> res;
        
        for(auto& it : prerequisites) {
            g[it[1]].push_back(it[0]);
            ++d[it[0]];
        }
        
        for(int i = 0; i < d.size(); ++i) {
            if(d[i] == 0) {
                n.push(i);
            }
        }
        
        while(!n.empty()){
            ++n_size;
            int id = n.front();
            n.pop();
            
            res.push_back(id);
            
            for(auto it : g[id]) {
                --d[it];
                
                if(d[it] == 0) n.push(it);
            }
        }
        
        return n_size == numCourses ? res : vector<int>();
    }
};
