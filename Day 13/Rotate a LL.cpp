/*
class Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* rotate(Node* head, int k) {
        vector<int>arr;
        
        Node *temp = head;
        
        while(temp != NULL)
        {
            arr.push_back(temp->data);
            temp = temp->next;
        }
        int n= arr.size();
         k = k % n;
         
         vector<int>res;
         
         for(int i=k;i<n;i++)
         {
             res.push_back(arr[i]);
         }
         for(int i=0;i<k;i++)
         {
             res.push_back(arr[i]);
         }
         temp = head;
         
         for(int i=0;i<n;i++)
         {
             temp->data = res[i];
             temp=temp->next;
         }
         return head;
    }
};
