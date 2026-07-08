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
TreeNode<int>* solve(vector<int> &inorder, vector<int> &preorder, int st, int end, int &indx)
{
    if(st > end)
    {
        return NULL;
    }

    int rootVal = preorder[indx];
    TreeNode<int>* root = new TreeNode<int>(rootVal);

    int i = st;
    for(;i<=end;i++)
    {
        if(rootVal == inorder[i])
        {
            break;
        }
    }
    indx++;
    root->left = solve(inorder, preorder,st,i-1,indx);
    root->right = solve(inorder,preorder,i+1,end,indx);

    return root;
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	int indx = 0;
    int n = inorder.size();

    return solve(inorder,preorder,0,n-1, indx);

}
