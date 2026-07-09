/* Structure of a Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
  public:
    bool solve(Node *root)
    {
        if(root==NULL)return true;
        if(root->left==NULL && root->right==NULL)return true;
        
        int left = root->left == NULL ? 0 : root->left->data;
        int right = root->right == NULL ? 0 : root->right->data;
        if(right + left != root->data)
        {
            return false;
        }
        
        return solve(root->left) && solve(root->right);
    }
    bool isSumProperty(Node *root) {
        // code here
        if(root==NULL)
        {
            return true;
        }
        return solve(root);
    }
};
