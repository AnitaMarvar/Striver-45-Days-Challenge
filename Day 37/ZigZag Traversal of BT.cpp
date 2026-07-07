/*
Definition for Node
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  void levelOrder(Node *root, vector<vector<int>>&ans)
  {
      queue<Node *>q;
      q.push(root);
      
      while(!q.empty())
      {
          int sz=q.size();
          vector<int>level;
          while(sz--)
          {
              auto node = q.front();
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
    vector<int> zigZagTraversal(Node* root) {
       vector<int>res;
       if(root==NULL)return res;
       
       vector<vector<int>>ans;
       
       levelOrder(root,ans);
       
       for(int i=0;i<ans.size();i++)
       {
           if(i % 2 == 1){
             for(int j=ans[i].size()-1;j>=0;j--)
             {
               res.push_back(ans[i][j]);
             }
           }
           else{
               for(int j=0;j<ans[i].size();j++)
               {
                   res.push_back(ans[i][j]);
               }
           }
       }
       return res;
        
    }
};
