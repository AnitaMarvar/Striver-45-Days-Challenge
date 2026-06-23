/*
class Node {
public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int cycleStart(Node* head) {
        if(head==NULL || head->next==NULL)return -1;
        
        Node *fast = head;
        Node *slow = head;
        
        while(fast != NULL && fast->next != NULL)
        {
            
            slow = slow->next;
            fast = fast->next->next;
            
            //cycle detected
            if(slow == fast)
            {
                slow = head;
                
                while(slow != fast)
                {
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow->data;
            }
        }
        return -1;
    }
};
