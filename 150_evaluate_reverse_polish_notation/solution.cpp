class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> ss;
        
        for(auto s: tokens) {
            if(s.size() > 1 || isdigit(s[0])) ss.push(stoi(s));
            else {
                int x2 = ss.top(); ss.pop();
                int x1 = ss.top(); ss.pop();
                
                switch(s[0]) {
                    case '+' : x1 += x2; break;
                    case '-' : x1 -= x2; break;
                    case '/' : x1 /= x2; break;
                    case '*' : x1 *= x2; break;
                }
                
                ss.push(x1);
            }
        }
        
        return ss.top();
    }
};
