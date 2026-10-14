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
    private:
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
        ListNode* first=head;
        ListNode* second=slow->next;
        slow->next=nullptr;
        second=reverseLL(second);
        ListNode* node=new ListNode(-1);
        ListNode* tail=node;
        while(first && second)
        {
            tail->next=first;
            tail=first;
            first=first->next;
            tail->next=second;
            tail=second;
            second=second->next;
        }
        if(first)
        {
            tail->next=first;
            tail=first;
        }if(second)
        {
            tail->next=second;
            tail=second;
        }
        head=node->next;
        return ;
    }
};
