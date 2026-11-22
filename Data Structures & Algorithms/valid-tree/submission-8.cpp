class Solution {
    bool dfs(int node,unordered_map<int,vector<int> >& adjList,unordered_map<int,int>& vis,int parent)
    {
        vis[node]=1;
        for(auto it: adjList[node])
        {
            if(!vis[it]) dfs(it,adjList,vis,node);
            else if(parent!=it) return true;
        }
        return false;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int> >adjList;
        for(auto it: edges)
        {
            int u=it[0];
            int v=it[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        unordered_map<int,int>vis;
        int noc=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                noc++;
                if(dfs(i,adjList,vis,-1)) return false;
            }
        }
        
        if(noc>1) return false;
        return true;
    }
};
