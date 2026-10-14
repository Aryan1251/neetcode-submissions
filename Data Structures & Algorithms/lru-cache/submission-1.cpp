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
    unordered_map<int,Node*>mp;
    int capacity;
    Node* head=new Node({-1,-1});
    Node* tail=new Node({-1,-1});
    LRUCache(int capacity) {
        this->capacity=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void InsertAtHead(Node* &head,Node* node)
    {
        head->next->prev=node;
        node->next=head->next;
        node->prev=head;
        head->next=node;

        return ;
    }
    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
            Node* node=mp[key];
            node->prev->next=node->next;
            node->next->prev=node->prev;

            InsertAtHead(head,node);

            auto p=node->p;
            return p.second;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(capacity==0)
        {
            if(mp.find(key)!=mp.end())
            {
                Node* node=mp[key];
                auto &p=node->p;
                p.second=value;

                node->prev->next=node->next;
                node->next->prev=node->prev;

                InsertAtHead(head,node);

                return ;
            }else
            {
                Node* nodeToDelete=tail->prev;
                auto p=nodeToDelete->p;
                int deleteKey=p.first;
                mp.erase(deleteKey);

                nodeToDelete->prev->next=tail;
                tail->prev=nodeToDelete->prev;

                delete nodeToDelete;

                Node* node=new Node({key,value});
                InsertAtHead(head,node);

                mp[key]=node;

                return ;
            }
        }
        else
        {
            if(mp.find(key)!=mp.end())
            {
                Node* node=mp[key];
                auto &p=node->p;
                p.second=value;
                
                node->prev->next=node->next;
                node->next->prev=node->prev;

                InsertAtHead(head,node);

                return ;
            }else
            {
                Node* node=new Node({key,value});
                InsertAtHead(head,node);
                mp[key]=node;

                capacity--;
                return ;
            }
        }
    }
};
