/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return root;
        inorder(root);
        prev->right = head;
        head->left = prev;
        return head;
    }

private:
    void inorder(Node* n) {
        if(!n) return;
        inorder(n->left);
        if(!head) head = n;
        if(prev) {
            prev->right = n;
            n->left = prev;
        }
        
        prev = n;
        inorder(n->right);
    }
    
    Node* prev = nullptr;
    Node* head = nullptr;
};
