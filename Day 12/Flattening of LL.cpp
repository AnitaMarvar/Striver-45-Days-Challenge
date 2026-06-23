/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
}; */

class Solution {
  public:
    Node *merge(Node *a, Node *b)
    {
        if(a==NULL)return b;
        if(b == NULL)return a;
        
        Node *res;
        
        if(a->data < b->data)
        {
            res = a;
            res->bottom = merge(a->bottom,b);  //put in bottom ptr given in ques
        }
        else{
            res = b;
            res->bottom = merge(a,b->bottom); //put in bottom ptr given in ques
        }
        res->next=NULL;
        return res;
    }
    Node *flatten(Node *root) {
        
        if(root==NULL || root->next==NULL)
        {
            return root;
        }
        
        root->next = flatten(root->next);
        root = merge(root, root->next);
        return root;
    }
};
