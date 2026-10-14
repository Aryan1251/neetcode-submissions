class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> >pq;
        unordered_map<int,vector<pair<int,int>> >adj;
        for(auto it: flights)
        {
            int u=it[0];
            int v=it[1];
            int cost=it[2];
            adj[u].push_back({v,cost});
        }
        pq.push({0,{src,0}});
        int ans=INT_MAX;
        while(!pq.empty())
        {
            int D=pq.top().first;
            int node=pq.top().second.first;
            int K=pq.top().second.second;
            if(node==dst)
            {
                if(K<=k+1) ans=min(ans,D);
            }
            pq.pop();

            for(auto it: adj[node])
            {
                int v=it.first;
                int cost=it.second;
                if(K<=k+1)
                {
                    pq.push({cost+D,{v,K+1}});
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};
