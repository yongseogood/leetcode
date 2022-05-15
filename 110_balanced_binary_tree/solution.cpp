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
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        
        int l = depth(root->left);
        int r = depth(root->right);
        
        return abs(l - r) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
private:
    int depth(TreeNode* root) {
        if(root == nullptr) return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }
};
