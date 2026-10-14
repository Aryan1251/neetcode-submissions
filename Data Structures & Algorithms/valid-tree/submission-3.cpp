class Solution {
    bool bfs(int node,unordered_map<int,vector<int> >& adj,unordered_map<int,int>& vis,vector<int>& parent)
    {
        queue<int>q;
        q.push(node);
        vis[node]=1;
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            for(auto it: adj[node])
            {
                if(!vis[it])
                {
                    vis[it]=1;
                    q.push(it);
                    parent[it]=node;
                }else if(parent[node]!=it) return true;
            }
        }
        return false;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int> >adj;
        for(auto it: edges)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        unordered_map<int,int>vis;
        vector<int>parent(n,-1);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                cnt++;
                if(bfs(i,adj,vis,parent))
                {
                     return false;
                }
            }
        }
        return cnt<=1;
    }
};
