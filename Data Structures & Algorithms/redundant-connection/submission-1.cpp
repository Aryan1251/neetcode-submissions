class Solution {
    void unionByRank(int u,int v,vector<int>& parent,vector<int>& rank)
    {
        if(rank[u]>rank[v])
        {
            rank[u]+=rank[v];
            parent[v]=u;
        }else
        {
            rank[v]+=rank[u];
            parent[u]=v;
        }
    }
    int findParent(int node,vector<int>& parent)
    {
        if(node==parent[node]) return node;
        else return parent[node]=findParent(parent[node],parent);
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>rank(n+1,1),parent(n+1,-1);
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
        }
        for(auto it: edges)
        {
            int u=it[0];
            int v=it[1];
            int uParent=findParent(u,parent);
            int vParent=findParent(v,parent);
            if(uParent!=vParent)
            unionByRank(uParent,vParent,parent,rank);
            else
            {
                return {u,v};
            }
        }
        return {};
    }
};
