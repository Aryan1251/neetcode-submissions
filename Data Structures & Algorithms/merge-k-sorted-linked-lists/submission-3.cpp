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
        int n=lists.size();
        for(int i=0;i<n;i++)
        {
            ListNode* node=lists[i];
            pq.push({node->val,node});
        }
        ListNode* head=new ListNode(-1);
        ListNode* temp=head;
        while(!pq.empty())
        {
            auto nodeData=pq.top().first;
            auto node=pq.top().second;
            pq.pop();
            ListNode* curr=new ListNode(nodeData);
            temp->next=curr;
            temp=curr;
            if(node->next) pq.push({node->next->val,node->next});
        }
        return head->next;
    }
};
