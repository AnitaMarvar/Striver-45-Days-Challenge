/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *reverseList(ListNode *head)
    {
        vector<int>arr;
        ListNode *temp=head;
        while(temp!=NULL)
        {
            arr.push_back(temp->val);
            temp=temp->next;
        }
        reverse(arr.begin(),arr.end());
        temp=head;
        for(int i=0;i<arr.size();i++)
        {
            temp->val = arr[i];
            temp=temp->next;
        }
        return head;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL)return NULL;
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;

        // l1 = reverseList(l1);
        // l2 = reverseList(l2);
        int carry = 0;
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;

        while(l1 != NULL || l2 != NULL || carry)
        {
            int sum = carry;
            if(l1)
            {
                sum += l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                sum += l2->val;
                l2=l2->next;
            }
             carry = sum / 10;
            ListNode *newNode = new ListNode(sum % 10);
            tail->next = newNode;
            tail = newNode;
        }
        return dummy->next;


    }
};
