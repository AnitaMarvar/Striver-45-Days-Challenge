/*
class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        if(head==NULL || head->next==NULL)return NULL;
       vector<int>arr;
       int cnt=0;
       Node *temp = head;
       while(temp != NULL)
       {
           if(cnt != x-1)
           {
            arr.push_back(temp->data);   
           }
           temp=temp->next;
           cnt++;
       }
       temp=head;
       for(int i=0;i<arr.size();i++)
       {
           if(i==arr.size()-1)
           {
               temp->data = arr[i];
               temp->next=NULL;
               break;
           }
           temp->data = arr[i];
           temp=temp->next;
       }
       return head;
       
    }
};
