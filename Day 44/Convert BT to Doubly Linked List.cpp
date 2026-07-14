#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void solve(BinaryTreeNode<int>* root, vector<BinaryTreeNode<int>*>&arr)
{
    if(root==NULL)return;

    solve(root->left,arr);
    arr.push_back(root);
    solve(root->right,arr);
}
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    if(root==NULL)return NULL;
    vector<BinaryTreeNode<int>*>arr;
    solve(root,arr);

    int n=arr.size();

    for(int i=0;i<n;i++)
    {
        if(i == 0)
        {
            arr[i]->left = NULL;
        }
        else{
            arr[i]->left = arr[i-1];
        }

        if(i == n-1)
        {
            arr[i]->right = NULL;
        }
        else{
            arr[i]->right = arr[i+1];
        }
    }
    return arr[0];


}
