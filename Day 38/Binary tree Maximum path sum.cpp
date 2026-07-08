#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int maxSum;
int solve(TreeNode<int>*root)
{
    if(root==NULL)return 0;

    int l = solve(root->left);
    int r = solve(root->right);

    int niche_hi_mil_gaye = l + r + root->val;
    int ek_hi_accha_hai = max(l,r) + root->val;
    int root_hi_accha_hai = root->val;

    maxSum = max({maxSum, niche_hi_mil_gaye,ek_hi_accha_hai,root_hi_accha_hai});

    return max(root_hi_accha_hai, ek_hi_accha_hai);
}
int maxPathSum(TreeNode<int>* root)
{
    maxSum = INT_MIN;
    solve(root);
	return maxSum;
}
