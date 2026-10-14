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
        Node* cloneHead=new Node(-1);
        Node* node=cloneHead;
        Node* curr=head;
        while(curr)
        {
            Node* currNode=new Node(curr->val);
            node->next=currNode;
            node=currNode;
            curr=curr->next;
        }
        cloneHead=cloneHead->next;
        Node* originalHead=head;
        Node* cloneHeadTemp=cloneHead;
        while(originalHead && cloneHeadTemp)
        {
            Node* node=originalHead->next;
            originalHead->next=cloneHeadTemp;
            Node* temp=cloneHeadTemp->next;
            cloneHeadTemp->next=node;
            originalHead=node;
            cloneHeadTemp=temp;
        }
        Node* temp=cloneHead;
        curr=head;
        while(curr && temp)
        {
            temp->random=curr->random ? curr->random->next : nullptr;
            curr=temp->next;
            if(curr)
            temp=curr->next;
        }
        temp=cloneHead;
        curr=head;
        while(curr && temp)
        {
            curr->next=temp->next;
            curr=curr->next;
            if(curr)
            temp->next=curr->next;
            temp=temp->next;
        }
        return cloneHead;
    }
};
