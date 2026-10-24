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
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr)
        {
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }

public:
    void reorderList(ListNode* head) {
        if(!head) return ;
        if(head->next==NULL) return ;
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

        ListNode* newNode=new ListNode(-1);
        ListNode* curr=newNode;
        while(head && newHead)
        {
            curr->next=head;
            curr=head;
            head=head->next;

            curr->next=newHead;
            curr=newHead;
            newHead=newHead->next;
        }
        if(head) curr->next=head;
        else if(newHead) curr->next=newHead;

        head=newNode->next;
        return ;

    }
};
