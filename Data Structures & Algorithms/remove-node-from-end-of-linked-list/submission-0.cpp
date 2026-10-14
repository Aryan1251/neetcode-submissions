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
    int lenLL(ListNode* head)
    {
        int cnt=0;
        while(head)
        {
            cnt++;
            head=head->next;
        }
        return cnt;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=lenLL(head);
        if(len-n==0)
        {
            ListNode* temp=head;
            head=head->next;
            temp->next=nullptr;
            delete temp;
            return head;
        }
        ListNode* temp=head;
        ListNode* prev=NULL;
        int cnt=len-n;
        while(temp!=NULL && cnt--)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        temp->next=NULL;
        delete temp;
        return head;
    }
};
