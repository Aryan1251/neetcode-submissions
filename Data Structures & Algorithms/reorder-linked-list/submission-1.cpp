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
        if(head->next==NULL) return ;
        ListNode* slow=head;
        ListNode* fast=head->next;
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
        slow->next=nullptr;
        newHead=reverseLL(newHead);
        ListNode* node=new ListNode(-1);
        ListNode* tail=node;
        while(head && newHead)
        {
            tail->next=head;
            tail=head;
            head=head->next;
            tail->next=newHead;
            tail=newHead;
            newHead=newHead->next;
        }
        if(head)
        {
            tail->next=head;
            tail=head;
        }
        else if(newHead) 
        {
            tail->next=newHead;
            tail=newHead;
        }
        head=node->next;
        return ;
    }
};
