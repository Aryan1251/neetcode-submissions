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
    ListNode* reverseLL(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr)
        {
            ListNode* nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        if(!head) return ;
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast)
        {
            fast=fast->next;
            if(fast)
            {
                fast=fast->next;
                slow=slow->next;
            }
        }
        ListNode* newHead=slow->next;
        slow->next=NULL;
        newHead=reverseLL(newHead);

        ListNode* ans=new ListNode(-1);
        ListNode* curr=ans;

        ListNode* temp1=head;
        ListNode* temp2=newHead;

        while(temp1 && temp2 && curr)
        {
            curr->next=temp1;
            curr=temp1;
            temp1=temp1->next;
            curr->next=temp2;
            curr=temp2;
            temp2=temp2->next;
        }
        if(temp1) curr->next=temp1;
        else if(temp2) curr->next=temp2;
        
        head=ans->next;
        return ;

    }
};
