class Solution {
    int findParent(int node,vector<int>& parent)
    {
        if(node==parent[node]) return parent[node];
        return parent[node]=findParent(parent[node],parent);
    }
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
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int> >adj;
        int n=points.size();
        int N=2*n;
        vector<int>parent(N,-1),rank(N,1);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int dis=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj.push_back({dis,i,j});
            }
        }
        sort(adj.begin(),adj.end());
        for(int i=0;i<N;i++)
        parent[i]=i;

        int ans=0;
        for(auto it: adj)
        {
            int wt=it[0];
            int u=it[1];
            int v=it[2];
            int uParent=findParent(u,parent);
            int vParent=findParent(v,parent);
            if(uParent!=vParent)
            {
                ans+=wt;
                unionByRank(uParent,vParent,parent,rank);
            }
        }
        return ans;
    }
};
