class Solution {
public:
    void pushLeft(std::stack<TreeNode*> &s, TreeNode* n)
    {
        while(n != nullptr)
        {
            s.push(n);
            n = n->left;
        }
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        std::vector<int> result;
        
        std::stack<TreeNode*> s1, s2;
        
        pushLeft(s1, root1);
        pushLeft(s2, root2);
        
        while(!s1.empty() || !s2.empty())
        {
            std::stack<TreeNode*> &s = s1.empty() ? s2 : s2.empty() ? s1 : s1.top()->val < s2.top()->val ? s1 : s2;
            auto n = s.top(); s.pop();
            
            result.push_back(n->val);
            pushLeft(s, n->right);
        }
        
        return result;
    }
};
