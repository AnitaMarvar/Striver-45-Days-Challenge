/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void solve(Node *root, vector<Node *>&ans)
    {
        if(root==NULL)return;
        solve(root->left,ans);
        ans.push_back(root);
        solve(root->right,ans);
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        vector<Node *>ans;
        solve(root,ans);
        
        Node *pre = NULL;
        Node *suc = NULL;
        
        for(int i=0;i<ans.size();i++)
        {
            int node = ans[i]->data;
            if(ans[i]->data < key)
            {
                pre = ans[i];
            }
            else if(ans[i]->data > key)
            {
                suc = ans[i];
                break;
            }
        }
        
        return {pre, suc};
    }
};
