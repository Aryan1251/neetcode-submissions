/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //base case
        if(!head) return head;
        Node* newHead=new Node(-1);
        Node* temp=newHead;
        Node* curr=head;

        while(curr)
        {
            Node* node=new Node(curr->val);
            temp->next=node;
            temp=node;
            curr=curr->next;
        }
        Node* prev=newHead;
        newHead=newHead->next;
        prev->next=nullptr;
        delete prev;

        unordered_map<Node*,Node*>mp;
        curr=head;
        temp=newHead;
        while(curr && temp)
        {
            mp[curr]=temp;
            curr=curr->next;
            temp=temp->next;
        }

        curr=head;
        temp=newHead;
        while(curr && temp)
        {
            temp->random=curr->random ? mp[curr->random] : NULL;
            curr=curr->next;
            temp=temp->next;
        }
        return newHead;
        
    }
};
