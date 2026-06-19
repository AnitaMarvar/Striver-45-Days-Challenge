/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/
#include <algorithm>
Node* removeKthNode(Node* head, int K)
{
    if(head==NULL || head->next==NULL)return NULL;
    vector<int>arr,ans;
    Node *temp = head;
    int cnt=0;
    while(temp != NULL)
    {
        arr.push_back(temp->data);
        temp=temp->next;
    }
    for(int i=arr.size()-1;i>=0;i--)
    {
        if(cnt == K-1)
        {

        }
        else{
        ans.push_back(arr[i]);
        }
        cnt++;
    }
    reverse(ans.begin(),ans.end());
   
    temp=head;
    for(int i=0;i<ans.size();i++)
    {
        if(i==ans.size()-1)
        {
            temp->data = ans[i];
            temp->next=NULL;
            break;
        }else{
        temp->data = ans[i];
        temp=temp->next;
        }
    }
    return head;

}
