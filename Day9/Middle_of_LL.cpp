 ListNode* middleNode(ListNode* head) {
        
        if(head==NULL)return NULL;

        ListNode *slow = head;
        ListNode *fast = head;

        while(fast!= NULL && fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
