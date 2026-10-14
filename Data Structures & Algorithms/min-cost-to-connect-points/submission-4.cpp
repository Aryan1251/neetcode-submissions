class Solution {
    int findParent(int node,vector<int>& parent)
    {
        if(node==parent[node]) return node;
        else return parent[node]=findParent(parent[node],parent);
    }
    void unionByRank(int u,int v,vector<int>& parent,vector<int>& rank)
    {
        if(rank[u]>rank[v])
        {
            parent[v]=u;
            rank[u]+=rank[v];
        }else
        {
            parent[u]=v;
            rank[v]+=rank[u];
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
                int dis=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({dis,i,j});
                edges.push_back({dis,j,i});
            }
        }
        sort(edges.begin(),edges.end());
        vector<int>parent(edges.size(),0),rank(edges.size(),1);

        for(int i=0;i<edges.size();i++) parent[i]=i;

        int cost=0;
        for(auto it: edges)
        {
            int wt=it[0];
            int u=it[1];
            int v=it[2];
            int uParent=findParent(u,parent);
            int vParent=findParent(v,parent);
            if(uParent!=vParent)
            {
                unionByRank(uParent,vParent,parent,rank);
                cost+=wt;
            }
        }
        return cost;
    }
};
