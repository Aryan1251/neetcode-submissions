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
    int getLength(ListNode* head)
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
        ListNode* prev=nullptr;
        ListNode* curr=head;
        int len=getLength(head);
        int cnt=len-n;
        while(cnt--)
        {
            prev=curr;
            curr=curr->next;
        }
        if(prev)
        {
            prev->next=curr->next;
            curr->next=nullptr;
            delete curr;
            return head;
        }else
        {
            head=curr->next;
            delete curr;
            return head;
        }
    }
};
