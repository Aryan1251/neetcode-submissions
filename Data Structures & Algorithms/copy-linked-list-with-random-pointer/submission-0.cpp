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
        unordered_map<Node*,Node*>originalToClone;
        Node* temp=head;
        Node* cloneHead=new Node(-1);
        Node* tail=cloneHead;
        while(temp)
        {
            Node* node=new Node(temp->val);
            tail->next=node;
            
            tail=node;
            originalToClone[temp]=node;
            temp=temp->next;
        }
        tail=cloneHead->next;
        temp=head;
        while(tail && temp)
        {
            tail->random=(temp->random)? originalToClone[temp->random] : nullptr;
            tail=tail->next;
            temp=temp->next;
        }
        return cloneHead->next;
        
    }
};
