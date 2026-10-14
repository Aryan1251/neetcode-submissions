class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> >pq;

        unordered_map<int,vector<pair<int,int>> >adj;

        for(auto it: flights)
        {
            int u=it[0];
            int v=it[1];
            int dist=it[2];
            adj[u].push_back({v,dist});
        }

        pq.push({0,{src,0}});
        int ans=INT_MAX;
        while(!pq.empty())
        {
            auto D=pq.top().first;
            auto node=pq.top().second.first;
            auto K=pq.top().second.second;
            if(node==dst) ans=min(ans,D);
            pq.pop();

            for(auto it: adj[node])
            {
                int nbrNode=it.first;
                int nbrD=it.second;
                if(K+1<=k+1)
                pq.push({nbrD+D,{nbrNode,K+1}});
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};
