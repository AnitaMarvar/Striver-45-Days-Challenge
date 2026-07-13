#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

class BSTiterator
{
    public:
    vector<int>ans;
    int ind=0;

    void solve(TreeNode<int>* root, vector<int>&ans)
    {
        if(root==NULL)return;

        solve(root->left,ans);
        ans.push_back(root->data);
        solve(root->right,ans);
    }
    BSTiterator(TreeNode<int> *root)
    {
        solve(root,ans);
    }

    int next()
    {
        return ans[ind++];
    }

    bool hasNext()
    {
        return ind < ans.size();
        // write your code here
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/
