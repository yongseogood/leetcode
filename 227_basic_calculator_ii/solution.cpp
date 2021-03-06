class Solution {
public:
    int calculate(string s) {
        istringstream in('+' + s + '+');
        long long total = 0, term = 0, n;
        char op;

        while(in >> op) {
            if(op == '+' || op == '-') {
                total += term;
                in >> term;
                term *= op == '+' ? 1 : -1;
            } else {
                in >> n;
                if(op == '*') term *= n;
                else term /= n;
            }
        }
        
        return total;
    }
};
