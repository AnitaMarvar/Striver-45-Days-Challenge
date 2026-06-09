 ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL && list2==NULL)return NULL;
        else if(list1==NULL)return list2;
        else if(list2==NULL)return list1;

        ListNode *temp = list1;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = list2;

        temp = list1;
        vector<int>arr;

        while(temp!=NULL)
        {
            arr.push_back(temp->val);
            temp=temp->next;
        }
        sort(arr.begin(),arr.end());
        temp = list1;
        for(int i=0;i<arr.size();i++)
        {
            temp->val = arr[i];
            temp=temp->next;
        }
        return list1;
        
    }
