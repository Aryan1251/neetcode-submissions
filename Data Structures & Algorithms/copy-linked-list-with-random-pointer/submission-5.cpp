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
        Node* curr=head;
        while(curr)
        {
            Node* nxt_node=curr->next;
            Node* node=new Node(curr->val);
            curr->next=node;
            node->next=nxt_node;
            curr=nxt_node;
        }

        curr=head;
        Node* newHead=curr->next;
        Node* temp=newHead;
        while(curr && temp)
        {
            temp->random=curr->random ? curr->random->next : nullptr;
            curr=temp->next;
            if(curr)
            temp=curr->next;
        }

        temp=newHead;
        while(temp)
        {
            Node* nxt_node=temp->next;
            if(nxt_node)
            temp->next=nxt_node->next;
            temp=temp->next;
        }
        return newHead;
    }
};
