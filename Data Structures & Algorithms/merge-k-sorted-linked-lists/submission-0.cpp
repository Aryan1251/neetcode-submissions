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
        int n=lists.size();
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>> >pq;
        for(int i=0;i<n;i++)
        {
            ListNode* temp=lists[i];
            pq.push({temp->val,lists[i]});
        }
        ListNode* head=new ListNode(-1);
        ListNode* tail=head;
        while(!pq.empty())
        {
            auto val=pq.top().first;
            auto node=pq.top().second;
            pq.pop();
            ListNode* newNode=new ListNode(val);
            tail->next=newNode;
            tail=newNode;

            if(node->next)
            {
                pq.push({node->next->val,node->next});
            }
        }
        return head->next;
        return nullptr;
    }
};
