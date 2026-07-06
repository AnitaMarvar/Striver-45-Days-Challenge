#include <bits/stdc++.h> 
//TreeNode class definition
/*
template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->val = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

*/

int findMaxDepth(TreeNode<int> *root) 
{
	if(root==NULL)
    {
        return 0;
    }
    int leftAns = findMaxDepth(root->left)+1;
    int rightAns = findMaxDepth(root->right)+1;
    return max(leftAns,rightAns);
}
