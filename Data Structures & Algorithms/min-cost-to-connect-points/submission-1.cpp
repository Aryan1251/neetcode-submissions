class Solution {
    bool static myComp(vector<int>& a,vector<int>& b)
    {
        return a[2]<b[2];
    }
    int findParent(vector<int>& parent,int node)
    {
        if(node==parent[node]) return node;
        else return parent[node]=findParent(parent,parent[node]);
    }
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
                int dis=abs(points[j][0]-points[i][0])+abs(points[j][1]-points[i][1]);
                adj.push_back({i,j,dis});
                adj.push_back({j,i,dis});
            }
        }
        sort(adj.begin(),adj.end(),myComp);
        vector<int>parent(n,-1),size(n,1);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        int sum=0;
        for(auto it: adj)
        {
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            int uParent=findParent(parent,u);
            int vParent=findParent(parent,v);
            if(uParent!=vParent)
            {
                unionBySize(uParent,vParent,parent,size);
                sum+=wt;
            }
        }
        return sum;
    }
};
