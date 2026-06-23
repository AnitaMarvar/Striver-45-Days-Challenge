/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = nullptr;
    }
};*/

class Solution {
  public:
    bool isPalindrome(Node *head) {
        if(head->next==NULL)return true;
        vector<int>arr;
        
        Node *temp = head;
        while(temp != NULL)
        {
            arr.push_back(temp->data);
            temp=temp->next;
        }
        int l=0;
        int r=arr.size()-1;
        while(l <= r)
        {
            if(arr[l] != arr[r])return false;
            else{
                l++;
                r--;
            }
        }
        return true;
        

        
    }
};
