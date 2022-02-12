class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>>to_routes;

        for(int i = 0; i < routes.size(); ++i) {
            for(int j : routes[i])
                to_routes[j].push_back(i);
        }
        
        queue<pair<int, int>> data;
        
        data.push({source, 0});
        
        unordered_set<int> seen = {source};
        
        while(!data.empty())
        {
            int stop = data.front().first, bus = data.front().second;
            data.pop();
            
            if(stop == target) return bus;
            
            for(int i : to_routes[stop]){
                for(int j : routes[i]) {
                    if(seen.find(j) == seen.end()) {
                        seen.insert(j);
                        data.push({j, bus + 1});
                    }
                }
                
                routes[i].clear();
            }
        }
        
        return -1;
    }
};
