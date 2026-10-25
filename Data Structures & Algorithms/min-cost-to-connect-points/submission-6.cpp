class Solution {
    int findParent(vector<int>& parent,int node)
    {
        if(node==parent[node]) return node;
        return parent[node]=findParent(parent,parent[node]);
    }
    void unionBySize(vector<int>& size,vector<int>& parent,int u,int v)
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
        vector<vector<int> >edges;
        int n=points.size();

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int dis=abs(points[j][0]-points[i][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({dis,i,j});
            }
        }
        vector<int>parent(n);
        vector<int>size(n,1);

        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }

        sort(edges.begin(),edges.end());
        int ans=0;
        for(auto edge: edges)
        {
            int dis=edge[0];
            int u=edge[1];
            int v=edge[2];

            int up=findParent(parent,u);
            int vp=findParent(parent,v);

            if(up!=vp)
            {
                ans+=dis;
                unionBySize(size,parent,up,vp);
            }
        }
        return ans;
    }
};
