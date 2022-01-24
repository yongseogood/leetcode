class Solution {
public:
    string simplifyPath(string path) {
        std::string result;
        std::string tmp;
        std::vector<std::string> list;

        std::stringstream ss {path};
        
        while(getline(ss, tmp, '/'))
        {
            if(tmp == "" || tmp == ".") continue;
            else if(tmp == ".." && !list.empty()) list.pop_back();
            else if(tmp != "..") list.push_back(tmp);
        }
        
        for(const auto & str : list) result += "/" + str;
        
        return list.empty() ? "/" : result;
    }
};
