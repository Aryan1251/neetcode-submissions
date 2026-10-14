class Node{
    public:
    pair<int,int>p;
    Node* prev;
    Node* next;

    Node(pair<int,int> p)
    {
        this->p=p;
        this->prev=nullptr;
        this->next=nullptr;
    }
};
class LRUCache {
public:
    Node* head=new Node({-1,-1});
    Node* tail=new Node({-1,-1});
    unordered_map<int,Node*>mp;
    int cap;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void InsertAtHead(Node* head,Node* node)
    {
        node->next=head->next;
        head->next->prev=node;
        head->next=node;
        node->prev=head;
        return ;
    }

    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
            Node* addr=mp[key];
            auto p=addr->p;
            addr->prev->next=addr->next;
            addr->next->prev=addr->prev;

            InsertAtHead(head,addr);

            return p.second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            Node* addr=mp[key];
            auto& p=addr->p;
            p.second=value;
            addr->prev->next=addr->next;
            addr->next->prev=addr->prev;
            InsertAtHead(head,addr);
            return ;
        }
        else
        {
            if(cap==0)
            {
                Node* nodeToDelete=tail->prev;
                auto p=nodeToDelete->p;
    
                int deleteKey=p.first;
    
                mp.erase(deleteKey);
    
                nodeToDelete->prev->next=tail;
    
                tail->prev=nodeToDelete->prev;
                delete nodeToDelete;
    
                Node* node=new Node({key,value});
                mp[key]=node;
                InsertAtHead(head,node);
            }else
            {
                Node* node=new Node({key,value});
                mp[key]=node;
                InsertAtHead(head,node);
                cap--;
                return ;
            }
        }
    }
};
