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
        if(lists.empty()) return nullptr;
        //MIN HEAP
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*> >,greater<pair<int,ListNode*>> >pq;

        for(auto list: lists)
        {
            auto head=list;
            if(head)
            {
                int data=head->val;
                pq.push({data,head});
            }
        }
        
        ListNode* head=new ListNode(-1);
        ListNode* temp=head;
        while(!pq.empty())
        {
            int node=pq.top().first;
            ListNode* curr=pq.top().second;
            pq.pop();
            ListNode* newNode=new ListNode(node);
            head->next=newNode;
            head=newNode;
            if(curr && curr->next)
            pq.push({curr->next->val,curr->next});
        }

        return temp->next;
        
    }
};
