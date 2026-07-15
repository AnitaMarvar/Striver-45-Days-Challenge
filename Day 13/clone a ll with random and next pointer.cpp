/*
class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
  public:
    Node* cloneLinkedList(Node* head) {
        if(head==NULL)return NULL;
        
        Node *temp = head;
        unordered_map<Node *, Node *>mp;
        
        while(temp != NULL)
        {
            mp[temp] = new Node(temp->data);
            temp = temp->next;
        }
        
        temp = head;
        while(temp != NULL)
        {
            mp[temp]->next = temp->next ? mp[temp->next] : NULL;
            mp[temp]->random = temp->random ? mp[temp->random] : NULL;
            temp = temp->next;
        }
        return mp[head];
        
    }
};
