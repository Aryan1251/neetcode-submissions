class Solution {
    void dfs(int node,unordered_map<int,int>& vis,unordered_map<int,vector<int> >& adj)
    {
        vis[node]=1;
        for(auto it: adj[node])
        {
            if(!vis[it])
            dfs(it,vis,adj);
        }
        return ;
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
        int cnt=0;
        unordered_map<int,int>vis;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                cnt++;
                dfs(i,vis,adj);
            }
        }
        return cnt;
    }
};
