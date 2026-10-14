class Solution {
    bool bfs(int node,vector<int>& parent,vector<int>& vis,unordered_map<int,vector<int> >& adj)
    {
        queue<int>q;
        q.push(node);
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            vis[node]=1;
            for(auto it: adj[node])
            {
                if(!vis[it])
                {
                    q.push(it);
                    parent[it]=node;
                }else if(parent[node]!=it) return false;
            }
        }
        return true;
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
        vector<int>parent(n,-1),vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                cnt++;
                if(!bfs(i,parent,vis,adj)) return false;
            }
        }
        return cnt<=1?true:false;
    }
};
