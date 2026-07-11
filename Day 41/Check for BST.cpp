/*
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
  void solve(Node *root, vector<int>&arr)
  {
      if(root==NULL)return ;
      solve(root->left,arr);
      arr.push_back(root->data);
      solve(root->right,arr);
  }
    bool isBST(Node* root) {
        if(root==NULL)return true;
       vector<int>arr;
       solve(root,arr);
       for(int i=1;i<arr.size();i++)
       {
           if(arr[i-1] >= arr[i])
           {
               return false;
           }
       }
       return true;
    }
};
