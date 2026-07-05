#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
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

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
  vector<int>ans;
  queue<pair<TreeNode<int> *, int>>q;
  map<int,vector<int>>mp;

  q.push({root,0});
  while(!q.empty())
  {
      TreeNode<int> *node = q.front().first;
      int hd = q.front().second;
      q.pop();

      mp[hd].push_back(node->data);  //push all the elements, unlike top and bottom view

      if(node->left)
      {
          q.push({node->left,hd-1});
      }
      if(node->right)
      {
          q.push({node->right,hd+1});
      }
  }
  for(auto it : mp)
  {
      for(auto x : it.second)
      {
          ans.push_back(x);
      }
  }
  return ans;




}
