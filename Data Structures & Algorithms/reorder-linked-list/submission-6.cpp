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
        ListNode* temp=nullptr;
        while(curr)
        {
            temp=curr->next;
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
        slow->next=nullptr;
        ListNode* head2=reverseLL(newHead);
        ListNode* ansHead=new ListNode(-1);
        ListNode* temp=ansHead;
        while(head2 && head)
        {
            temp->next=head;
            temp=head;
            head=head->next;
            temp->next=head2;
            temp=head2;
            if(head2)
            head2=head2->next;
        }
        if(head2==NULL) temp->next=head;
        else if(head==NULL) temp->next=head2;
        head=ansHead->next;
        return ;
    }
};
