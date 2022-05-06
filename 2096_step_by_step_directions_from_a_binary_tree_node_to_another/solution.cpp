/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        root = lca(root, startValue, destValue);
        
        string p1, p2;
        getPath(root, startValue, p1);
        getPath(root, destValue, p2);
        
        for(char& c : p1) c = 'U';
        return p1 + p2;
    }

private:
    TreeNode* lca(TreeNode* root, int s, int d) {
        if(!root) return nullptr;
        if(root->val == s) return root;
        if(root->val == d) return root;
        
        auto l = lca(root->left, s, d);
        auto r = lca(root->right, s, d);
        
        if(l && r) return root;
        
        return l ? l : r;
    }
    
    bool getPath(TreeNode* root, int v, string& p) {
        if(!root) return false;
        if(root->val == v) return true;
        
        p += 'L';
        if(getPath(root->left, v, p)) return true;
        
        p.pop_back();
        p += 'R';
        if(getPath(root->right, v,p)) return true;
        p.pop_back();
        
        return false; 
    }
};  
