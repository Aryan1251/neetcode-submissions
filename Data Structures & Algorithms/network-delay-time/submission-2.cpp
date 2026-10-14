class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;
        unordered_map<int,vector<pair<int,int>> >adj;
        for(auto it: times)
        {
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
        }
        vector<int>dis(n+1,INT_MAX);
        pq.push({0,k});
        dis[k]=0;
        while(!pq.empty())
        {
            auto node=pq.top().second;
            auto T=pq.top().first;
            pq.pop();
            for(auto it: adj[node])
            {
                if(it.second+T<dis[it.first])
                {
                    dis[it.first]=it.second+T;
                    pq.push({it.second+T,it.first});
                }
            }
        }
        int maxi=INT_MIN;
        for(int i=1;i<=n;i++)
        {
            if(dis[i]==INT_MAX) return -1;
            maxi=max(maxi,dis[i]);
        }
        return maxi;

    }
};
