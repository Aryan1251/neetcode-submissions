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
        for(int i=0;i<lists.size();i++)
        {
            ListNode* node=lists[i];
            pq.push({node->val,node});
        }
        ListNode* head=new ListNode(-1);
        ListNode* temp=head;
        while(!pq.empty())
        {
            auto val=pq.top().first;
            auto node=pq.top().second;
            pq.pop();

            ListNode* currNode=new ListNode(val);
            temp->next=currNode;
            temp=currNode;
            if(node->next)
            pq.push({node->next->val,node->next});
        }
        return head->next;
    }
};
