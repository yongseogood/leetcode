class Solution {
public:
    bool isValid(string s) {
        stack<char> par;
        
        for(char& c: s)
        {
            switch (c)
            {
                case '(':
                case '{':
                case '[': par.push(c); break;
                case ')': if(par.empty() || par.top() != '(') return false; else par.pop(); break;
                case '}': if(par.empty() || par.top() != '{') return false; else par.pop(); break;
                case ']': if(par.empty() || par.top() != '[') return false; else par.pop(); break;
                default: break;
            }
        }
        
        return par.empty();
    }
};
