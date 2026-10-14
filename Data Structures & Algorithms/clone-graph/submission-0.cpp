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
    void dfs(Node* node,Node*& cloneNode,unordered_map<Node*,Node*>& mp)
    {
        for(auto it: node->neighbors)
        {
            if(!mp[it])
            {
                Node* adjNode=new Node(it->val);
                mp[it]=adjNode;
                auto &v=cloneNode->neighbors;
                v.push_back(adjNode);
                dfs(it,adjNode,mp);
            }else
            {
                auto &v=cloneNode->neighbors;
                v.push_back(mp[it]);
            }
        }
        return ;
    }
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        Node* cloneNode=new Node(node->val);
        unordered_map<Node*,Node*>mp;
        mp[node]=cloneNode;
        dfs(node,cloneNode,mp);
        return cloneNode;
    }
};
