class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> >pq;
        unordered_map<int,vector<pair<int,int>> >adj;

        for(auto it: flights)
        {
            int u=it[0];
            int v=it[1];
            int price=it[2];
            adj[u].push_back({v,price});
        }


        pq.push({0,{0,src}});
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        int ans=INT_MAX;
        while(!pq.empty())
        {
            auto K=pq.top().first;
            auto D=pq.top().second.first;
            auto node=pq.top().second.second;

            pq.pop();
            if(node==dst)
            {
                if(K-1<=k)
                {
                    ans=min(ans,D);
                }
            }

            for(auto it: adj[node])
            {
                int v=it.first;
                int price=it.second;
                if(D+price<dist[v])
                {
                    dist[v]=D+price;
                    pq.push({K+1,{dist[v],v}});
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};
