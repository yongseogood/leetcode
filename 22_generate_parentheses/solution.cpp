class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(res, "", n, n);
        return res;
    }
private:
    void helper(vector<string> &v, string str, int left, int right) {
        if(left == 0 && right == 0) {
            v.push_back(str);
            return;
        }
        
        if(left > 0) { helper(v, str + "(", left - 1, right); }
        if(right > left) { helper(v, str + ")", left, right - 1); }
    }
};
