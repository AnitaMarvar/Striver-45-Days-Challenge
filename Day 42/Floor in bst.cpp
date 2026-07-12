/*
Definition for Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    void solve(Node *root, vector<int>&ans)
    {
        if(root==NULL)
        {
            return;
        }
        solve(root->left,ans);
        ans.push_back(root->data);
        solve(root->right,ans);
    }
    int findMaxFork(Node* root, int k) {
        vector<int>ans;
        solve(root,ans);
        int res=-1;
        
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i] < k)
            {
                res = ans[i];
            }
            else if(ans[i]==k)
            {
                return ans[i];
            }
        }
        return res;
    }
};
