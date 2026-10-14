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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        else if(list2==NULL) return list1;
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        ListNode* newHead=new ListNode(-1);
        ListNode* node=newHead;
        while(temp1 && temp2)
        {
            if(temp1->val<temp2->val)
            {
                node->next=temp1;
                node=temp1;
                temp1=temp1->next;
            }else
            {
                node->next=temp2;
                node=temp2;
                temp2=temp2->next;
            }
        }
        if(temp1) node->next=temp1;
        else if(temp2) node->next=temp2;
        return newHead->next;
    }
};
