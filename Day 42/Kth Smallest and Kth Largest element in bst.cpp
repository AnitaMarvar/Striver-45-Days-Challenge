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
    void solve(Node *root, vector<int>&ans)
    {
        if(root==NULL)return;
        solve(root->left,ans);
        ans.push_back(root->data);
        solve(root->right,ans);
    }
    int kthSmallest(Node *root, int k) {
        vector<int>ans;
        solve(root,ans);
        if(k > ans.size())return -1;
        
        return ans[k-1];
        
    }
};


// kth largest


/* Structure of a Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    void solve(Node *root, vector<int>&ans)
    {
        if(root==NULL)return;
        solve(root->left,ans);
        ans.push_back(root->data);
        solve(root->right,ans);
    }
    int kthLargest(Node *root, int k) {
        vector<int>ans;
        solve(root,ans);
        if(k > ans.size())return -1;
        int n = ans.size();
        
        return ans[n-k];
        
    }
};



















