/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

string serializeTree(TreeNode<int> *root)
{
    string ans="";
    if(root==NULL)return ans;
    queue<TreeNode<int>*>q;
    q.push(root);

    while(!q.empty())
    {
        TreeNode<int>* node = q.front();
        q.pop();

        if(node == NULL)
        {
            ans += "-1 ";
        }
        else{
            ans += to_string(node->data) + " ";
            q.push(node->left);
            q.push(node->right);
        }
    }
    return ans;
}

TreeNode<int>* deserializeTree(string &serialized)
{
    if(serialized.empty())return NULL;
    vector<int>arr;
    string num="";

    for(char ch : serialized)
    {
        if(ch == ' ')
        {
            if(!num.empty()){
                arr.push_back(stoi(num));
                num="";
            }
        }
        else{
            num += ch;
        }
    }
    if(!num.empty())
    {
        arr.push_back(stoi(num));
    }

    TreeNode<int>* root = new TreeNode<int>(arr[0]);
    int i=1;
    queue<TreeNode<int>*>q;
    q.push(root);

    while(!q.empty() && i < arr.size())
    {
        TreeNode<int>* curr = q.front();
        q.pop();

        if(arr[i] != -1)
        {
            curr->left = new TreeNode<int>(arr[i]);
            q.push(curr->left);
        }
        i++;
        if(i < arr.size() && arr[i] != -1)
        {
            curr->right = new TreeNode<int>(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;

}



