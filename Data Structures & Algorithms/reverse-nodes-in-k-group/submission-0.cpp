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
    int lengthLL(ListNode* head)
    {
        int cnt=0;
        while(head)
        {
            cnt++;
            head=head->next;
        }
        return cnt;
    }
    ListNode* Solve(ListNode* head,int k)
    {
        if(!head) return head;

        int cnt=0;
        int len=lengthLL(head);
        if(len<k) return head;
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(cnt<k)
        {
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
            cnt++;
        }
        head->next=Solve(curr,k);
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        head=Solve(head,k);
        return head;
    }
};
