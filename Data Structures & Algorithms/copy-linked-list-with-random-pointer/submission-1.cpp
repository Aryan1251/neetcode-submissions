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
        if(!head) return head;
        
        Node* cloneHead=new Node(-1);
        Node* tail=cloneHead;
        Node* temp=head;
        while(temp)
        {
            Node* newNode=new Node(temp->val);
            tail->next=newNode;
            tail=newNode;
            temp=temp->next;
        }
        cloneHead=cloneHead->next;
        unordered_map<Node*,Node*>oldToNew;
        Node* cloneTail=cloneHead;
        temp=head;
        while(temp && cloneTail)
        {
            oldToNew[temp]=cloneTail;
            temp=temp->next;
            cloneTail=cloneTail->next;
        }
        temp=head;
        cloneTail=cloneHead;
        while(temp)
        {
            Node* curr=temp->random;
            if(curr==nullptr)
            cloneTail->random=curr;
            else
            cloneTail->random=oldToNew[curr];

            cloneTail=cloneTail->next;
            temp=temp->next;
        }
        return cloneHead;
    }
};
