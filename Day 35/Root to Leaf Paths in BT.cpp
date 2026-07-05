/********************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
    
********************************************************************/
void dfs(BinaryTreeNode < int > * root, vector<string>&ans,string s)
{
    if(root==NULL)return ;
    s += to_string(root->data);

    if(root->left==NULL && root->right==NULL)
    {
        ans.push_back(s);
        return;
    }

    s += " ";

    dfs(root->left,ans,s);
    dfs(root->right,ans,s);



}
vector < string > allRootToLeaf(BinaryTreeNode < int > * root) {
   vector<string>ans;
    string s="";
   dfs(root,ans,s);

   return ans;
}
