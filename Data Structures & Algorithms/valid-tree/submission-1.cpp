class Solution {
    private:
    bool dfs(int node,unordered_map<int,int>& vis,unordered_map<int,vector<int> >& adj,int parent)
    {
        vis[node]=1;
        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it,vis,adj,node)) return true;
            }else if(it!=parent)
            {
                return true;
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
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                cnt++;
                if(dfs(i,vis,adj,-1)) return false;
            }
        }
        return cnt<=1?true:false;
    }
};
