class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        
        int m_i = -1, m_d = -1, l = -1, r = -1;
    
        for(int i = s.size() - 1; i >=0; --i) {
            if(s[i] > m_d) {
                m_d = s[i];
                m_i = i;
            } else if (s[i] < m_d) {
                l = i;
                r = m_i;
            }
        }
        
        if(l == -1) return num;
        
        swap(s[l], s[r]);
        
        return stoi(s);
    }
};
