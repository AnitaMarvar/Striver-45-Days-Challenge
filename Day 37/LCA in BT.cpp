/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    Node* lca(Node* root, int n1, int n2) {
        //  code here
        if(root==NULL || n1 == root->data || n2 == root->data)return root;
        
        Node *lefty = lca(root->left,n1,n2);
        Node *righty = lca(root->right,n1,n2);
        
        if(lefty != NULL && righty != NULL)
        {
            return root;   //new root for further traversal
        }
        
        return lefty != NULL ? lefty : righty;   
    }
};
