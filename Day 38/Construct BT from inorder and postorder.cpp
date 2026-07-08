/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
TreeNode<int>* solve(vector<int>& postOrder, vector<int>& inOrder,int stIn, int endIn,int stPost,int endPost)
{
     if(stIn > endIn){
          return NULL;
     }
     TreeNode<int>* root = new TreeNode<int>(postOrder[endPost]);
     int i = stIn;
     for(;i<=endIn;i++)
     {
          if(inOrder[i]==root->data)
          {
               break;
          }
     }
     int leftSize = i - stIn;
     int rightSize = endIn - i;

     root->left = solve(postOrder,inOrder,stIn,i-1,stPost,stPost + leftSize -1);
     root->right = solve(postOrder,inOrder,i+1,endIn,endPost-rightSize, endPost -1);
     return root;
}
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder){
	int n=postOrder.size();

     int stIn = 0;
     int endIn = n-1;

     int stPost = 0;
     int endPost = n-1;

     return solve(postOrder,inOrder,stIn,endIn, stPost, endPost);
}
