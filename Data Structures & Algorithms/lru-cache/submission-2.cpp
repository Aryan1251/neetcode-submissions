class Node{
    public:
    pair<int,int>p;
    Node* prev;
    Node* next;
    Node(pair<int,int>p)
    {
        this->p=p;
        this->prev=NULL;
        this->next=NULL;
    }
};

class LRUCache {
public:
    unordered_map<int,Node*>mp;
    Node* head=new Node({-1,-1});
    Node* tail=new Node({-1,-1});
    int Capacity;
    LRUCache(int capacity) {
        Capacity=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
            auto node=mp[key];
            auto& p=node->p;
            node->prev->next=node->next;
            node->next->prev=node->prev;
            InsertAtHead(head,node);
            return p.second;
        }else
        return -1;
    }
    void InsertAtHead(Node* head,Node* node)
    {
        node->next=head->next;
        head->next->prev=node;
        node->prev=head;
        head->next=node;
        return ;
    }
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            Node* node=mp[key];
            auto &p=node->p;
            p.second=value;
            node->prev->next=node->next;
            node->next->prev=node->prev;
            InsertAtHead(head,node);
            return ;
        }else if(mp.size()==Capacity)
        {
            Node* nodeToDelete=tail->prev;
            nodeToDelete->prev->next=tail;
            tail->prev=nodeToDelete->prev;
            auto& p=nodeToDelete->p;
            int deleteKey=p.first;
            mp.erase(deleteKey);

            delete nodeToDelete;
            Node* node=new Node({key,value});
            mp[key]=node;
            InsertAtHead(head,node);
        }else
        {
            Node* node=new Node({key,value});
            mp[key]=node;
            InsertAtHead(head,node);
        }
    }
};
