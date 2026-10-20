class Solution {
    int findParent(int node,vector<int>& parent)
    {
        if(parent[node]==node) return node;
        return parent[node]=findParent(parent[node],parent);
    }
    void unionBySize(int up,int vp,vector<int>& parent,vector<int>& size)
    {
        if(size[up]>size[vp])
        {
            size[up]+=size[vp];
            parent[vp]=up;
        }else
        {
            size[vp]+=size[up];
            parent[up]=vp;
        }
        return ;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>parent(n+1,1);
        vector<int>size(n+1,1);

        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
        }

        for(auto edge: edges)
        {
            int u=edge[0];
            int v=edge[1];
            int u_p=findParent(u,parent);
            int v_p=findParent(v,parent);

            if(u_p!=v_p)
            {
                unionBySize(u_p,v_p,parent,size);
            }else
            {
                //already present means its an extra edge
                return {u,v};
            }
        }
        return {-1,-1};
    }
};
