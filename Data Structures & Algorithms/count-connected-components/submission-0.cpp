class Solution {
    void dfs(int node,unordered_map<int,int>& vis,unordered_map<int,vector<int> >& adj)
    {
        vis[node]=1;
        for(auto it: adj[node])
        {
            if(!vis[it])
            dfs(it,vis,adj);
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int> >adj;
        for(auto it: edges)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        unordered_map<int,int>vis;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,adj);
                cnt++;
            }
        }
        return cnt;
    }
};
