#include <bits/stdc++.h> 
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void levelOrder(BinaryTreeNode<int> *root, vector<vector<int>>&res)
{
    queue<BinaryTreeNode<int> *>q;
    q.push(root);
    while(!q.empty())
    {
        int sz=q.size();
        vector<int>level;
        for(int i=0;i<sz;i++)
        {
            BinaryTreeNode<int> *node = q.front();
            q.pop();
            level.push_back(node->val);

            if(node->left)
            {
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }
        }
        res.push_back(level);
    }
}
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    vector<int>ans;
    if(root==NULL)return ans;
    vector<vector<int>>res;

    levelOrder(root,res);

    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            ans.push_back(res[i][j]);
        }
    }
    return ans;
}
