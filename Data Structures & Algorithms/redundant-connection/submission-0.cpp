class Solution {
    void unionBySize(int u,int v,vector<int>& parent,vector<int>& size)
    {
        if(size[u]>size[v])
        {
            size[u]+=size[v];
            parent[v]=u;
        }else
        {
            size[v]+=size[u];
            parent[u]=v;
        }
    }
    int findParent(int node,vector<int>& parent)
    {
        if(parent[node]==node) return node;
        return parent[node]=findParent(parent[node],parent);
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>parent(n+1),size(n+1,1);
        for(int i=0;i<n+1;i++)
        parent[i]=i;

        vector<int>ans;
        for(auto it: edges)
        {
            int u=it[0];
            int v=it[1];
            int uParent=findParent(u,parent);
            int vParent=findParent(v,parent);
            if(uParent!=vParent)
            {
                unionBySize(uParent,vParent,parent,size);
            }else
            {
                ans.push_back(u);
                ans.push_back(v);
                return ans;
            }
        }
        return {};
    }
};
