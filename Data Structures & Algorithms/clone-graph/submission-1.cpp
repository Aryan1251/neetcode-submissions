/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    private:
    void dfs(Node* cloneNode,Node* node,unordered_map<Node*,Node*>& mp)
    {
        for(auto it:node->neighbors)
        {
            if(mp.find(it)!=mp.end())
            {
                Node* nbr=mp[it];
                auto& v=cloneNode->neighbors;
                v.push_back(nbr);
            }else
            {
                Node* newNode=new Node(it->val);
                mp[it]=newNode;
                auto& v=cloneNode->neighbors;
                v.push_back(newNode);
                dfs(newNode,it,mp);
            }
        }
        return ;
    }
        
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        unordered_map<Node*,Node*>mp;
        Node* cloneNode=new Node(node->val);
        mp[node]=cloneNode;
        dfs(cloneNode,node,mp);
        return cloneNode;
    }
};
