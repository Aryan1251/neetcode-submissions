class Solution {
    int findParent(int node,vector<int>& parent)
    {
        if(parent[node]==node) return node;
        return parent[node]=findParent(parent[node],parent);
    }
    void unionBySize(int u,int v,vector<int>& parent,vector<int>& size)
    {
        if(size[u]>size[v])
        {
            parent[v]=u;
            size[u]+=size[v];
        }else
        {
            parent[u]=v;
            size[v]+=size[u];
        }
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int> >adj;
        int n=points.size();
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int dis=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj.push_back({dis,i,j});
            }
        }
        sort(adj.begin(),adj.end());
        // for(auto it: adj)
        // {
        //     cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl;
        // }
        vector<int>parent(n+1),size(n+1,1);

        for(int i=0;i<n;i++)
        parent[i]=i;

        int ans=0;
        for(auto it: adj)
        {
            int dis=it[0];
            int u=it[1];
            int v=it[2];
            int uParent=findParent(u,parent);
            int vParent=findParent(v,parent);
            if(uParent!=vParent)
            {
                unionBySize(uParent,vParent,parent,size);
                ans+=dis;
            }
        }
        return ans;
    }
};
