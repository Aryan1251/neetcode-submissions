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
    int lengthLL(ListNode* head)
    {
        int len=0;
        while(head)
        {
            head=head->next;
            len++;
        }
        return len;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL)
        {
            return NULL;
        } 
        int len=lengthLL(head);
        int cnt=len-n-1;
        if(cnt<0)
        {
            ListNode* temp=head;
            head=head->next;
            temp->next=NULL;
            delete temp;
            return head;
        }
        ListNode* prev=head;
        ListNode* curr=head->next;

        while(cnt--)
        {
            prev=curr;
            curr=curr->next;
        }

        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
        return head;
    }
};
