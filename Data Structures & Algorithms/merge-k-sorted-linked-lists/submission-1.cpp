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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>> >pq;
        for(auto it:lists)
        {
            pq.push({it->val,it});
        }
        ListNode* head=new ListNode(-1);
        ListNode* tail=head;
        while(!pq.empty())
        {
            int data=pq.top().first;
            auto node=pq.top().second;
            pq.pop();

            ListNode* newNode=new ListNode(data);
            tail->next=newNode;
            tail=newNode;
            if(node->next)
            {
                pq.push({node->next->val,node->next});
            }
        }
        return head->next;
    }
};
