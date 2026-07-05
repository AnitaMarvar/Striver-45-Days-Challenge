#include <bits/stdc++.h> 
/*******************************************
  Following is the BinaryTreeNode structure

    template<typename T>
    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

********************************************/
void levelOrder(BinaryTreeNode<int> *root, vector<vector<int>>&ans)
{
    queue<BinaryTreeNode<int> *>q;
    q.push(root);

    while(!q.empty())
    {
        int sz = q.size();
        vector<int>level;
        for(int i=0;i<sz;i++)
        {
            BinaryTreeNode<int> *node = q.front();
            q.pop();
            level.push_back(node->data);

            if(node->left)
            {
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }
        }
        ans.push_back(level);
    }
}
int getMaxWidth(BinaryTreeNode<int> *root)
{
    if(root==NULL)return 0;
    vector<vector<int>>ans;

    levelOrder(root,ans);
    int maxi=-1;
    for(auto it : ans)
    {
        int n = it.size();
        maxi = max(maxi, n);
    }
    return maxi;

}
