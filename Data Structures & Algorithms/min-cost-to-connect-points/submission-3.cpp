class Solution {
    bool static myComp(vector<int>& a,vector<int>& b)
    {
        return a[2]<b[2];
    }
    int findParent(int node,vector<int>& parent)
    {
        if(node==parent[node]) return node;
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
        return ;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<int> >adj;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int dis=abs(points[j][0]-points[i][0])+abs(points[i][1]-points[j][1]);
                adj.push_back({i,j,dis});
                adj.push_back({j,i,dis});
            }
        }
        vector<int>parent(n,1),size(n,1);
        for(int i=0;i<n;i++)
        parent[i]=i;

        sort(adj.begin(),adj.end(),myComp);
        int sum=0;
        for(auto it: adj)
        {
            int u=it[0];
            int v=it[1];
            int cost=it[2];
            int uParent=findParent(u,parent);
            int vParent=findParent(v,parent);
            if(uParent!=vParent)
            {
                unionBySize(uParent,vParent,parent,size);
                sum+=cost;
            }
        }
        return sum;
    }
};
