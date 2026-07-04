/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T dat)
        {
            this->data = dat;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include <map>
#include <queue>
vector<int> getTopView(TreeNode<int> *root)
{
   vector<int>ans;
   map<int, TreeNode<int> *>mp;  //vertical line, node

   queue<pair<int,TreeNode<int> *>>q;
   q.push({0,root});

   while(!q.empty())
   {
       int line = q.front().first;
       TreeNode<int> * node = q.front().second;
       q.pop();

       if(mp.find(line) == mp.end())
       {
           mp[line] = node;
       }
       if(node->left)
       {
           q.push({line-1,node->left});
       }
       if(node->right)
       {
           q.push({line+1,node->right});
       }
   }
   for(auto it : mp)
   {
       ans.push_back(it.second->data);
   }
   return ans;
}
