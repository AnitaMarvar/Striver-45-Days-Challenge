/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    vector<int> inOrder(Node* root) {
        vector<int>ans;
        
        Node *curr = root;
        while(curr != NULL)
        {
            if(curr->left == NULL)
            {
                ans.push_back(curr->data);  //L, val, R
                curr = curr->right;
            }
            else{
                //find Inorder Predecessor
                Node *IP = curr->left;
                while(IP->right != NULL && IP->right != curr)
                {
                    IP = IP->right;
                }
                if(IP->right == NULL)
                {
                    //connection is not made
                    IP->right = curr;
                    curr = curr->left;
                }
                else{
                    //temp connection is made, remove it, make it as it was(OG)
                    IP->right = NULL;
                    ans.push_back(curr->data);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};
