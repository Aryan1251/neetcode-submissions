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
#define ll ListNode*

class Solution {
    private:
    int lengthLL(ll head)
    {
        int cnt=0;
        while(head)
        {
            head=head->next;
            cnt++;
        }
        return cnt;
    }
    ll Solve(ll head,int k)
    {
        int len=lengthLL(head);
        if(len<k) return head;
        ll prev=nullptr;
        ll curr=head;
        int cnt=k;
        while(k-- && curr)
        {
            ll nxt_node=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt_node;
        }
        head->next=Solve(curr,cnt);
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL) return head;
        return Solve(head,k);
    }
};
