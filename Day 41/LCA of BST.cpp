/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        // code here
        if(root==NULL || n1 == NULL || n2==NULL)return NULL;
        
        if(root->data > n1->data && root->data > n2->data)
        {
            return LCA(root->left, n1, n2);
        }
        else if(root->data < n1->data && root->data < n2->data)
        {
            return LCA(root->right,n1,n2);
        }
        else{
            return root;
        }
        return NULL;
    }
};
