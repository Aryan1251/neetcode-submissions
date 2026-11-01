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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==nullptr) return l2;
        if(l2==nullptr) return l1;
        int carry=0;
        ListNode* l3=new ListNode(-1);
        ListNode* temp=l3;
        while(l1 || l2)
        {
            int data=(l1 ? l1->val : 0 )+ (l2 ? l2->val : 0) + carry;
            int value=data%10;
            ListNode* node=new ListNode(value);
            temp->next=node;
            temp=node;

            carry=data/10;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        if(carry)
        {
            ListNode* node=new ListNode(carry);
            temp->next=node;
        }
        temp=l3;
        l3=l3->next;
        temp->next=nullptr;
        delete temp;

        return l3;

    }
};
