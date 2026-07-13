#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

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
void solve(TreeNode < int > * root,vector<int>&ans)
{
    if(root==NULL)
    {
        return;
    }
    solve(root->left,ans);
    ans.push_back(root->data);
    solve(root->right,ans);
}
bool kSumPair(TreeNode < int > * root, int k) {
    vector<int>ans;
    solve(root,ans);
    int j = ans.size()-1;
    int i=0;
    while(i<j)
    {
        if(ans[i]+ans[j]==k)
        {
            return true;
        }
        else if(ans[i]+ans[j] > k)
        {
            j--;
        }
        else{
            i++;
        }
    }
    return false;
}
