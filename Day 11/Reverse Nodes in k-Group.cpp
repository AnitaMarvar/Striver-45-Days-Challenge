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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int>nums;
        ListNode *temp = head;
        while(temp != NULL)
        {
            nums.push_back(temp->val);
            temp=temp->next;
        }

        for(int i=0;i <= nums.size()-k;i=i+k)
        {
            reverse(nums.begin()+i, nums.begin()+i+k);
        }
        temp=head;
        for(int i=0;i<nums.size();i++)
        {
            temp->val = nums[i];
            temp=temp->next;
        }
        return head;
    }
};
