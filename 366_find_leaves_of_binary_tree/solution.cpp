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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        helper(root, res);
        return res;
    }
private:
    
    int helper(TreeNode* root, vector<vector<int>>& res) {
        if(!root) return 0;
        int level = max(helper(root->left, res), helper(root->right, res)) + 1;
        if(level > (int)res.size()) res.push_back(vector<int>());
        res[level - 1].push_back(root->val);
        return level;
    }
};
