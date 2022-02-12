class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        std::unordered_set<std::string> result;
        
        for(const std::string & email : emails)
        {
            std::string newEmail;
            
            for(const char & c : email)
            {
                if(c == '+' || c == '@') break;
                else if (c == '.') continue;
                
                newEmail += c;
            }
            
            newEmail += email.substr(email.find('@'));
            
            result.insert(newEmail);
        }
        
        return result.size();
    }
};
