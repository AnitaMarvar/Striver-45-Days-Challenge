/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
class Info{
    public:
    int mini, maxi, sz;

    Info(int mini, int maxi, int sz)
    {
        this->mini = mini;
        this->maxi = maxi;
        this->sz = sz;
    }
};
Info helper(TreeNode *root)
{
    if(root==NULL)
    {
        return Info(INT_MAX, INT_MIN, 0);
    }

    Info left = helper(root->left);
    Info right = helper(root->right);

    if(root->data > left.maxi && root->data < right.mini)
    {
        //valid bst
        int currMin = min(root->data, left.mini);
        int currMax = max(root->data, right.maxi);
        int currSz = left.sz + right.sz + 1;
        return Info(currMin, currMax, currSz);
    }
    return Info(INT_MIN, INT_MAX, max(left.sz, right.sz));
}
int largestBST(TreeNode * root){
    Info info = helper(root);

    return info.sz;
}
