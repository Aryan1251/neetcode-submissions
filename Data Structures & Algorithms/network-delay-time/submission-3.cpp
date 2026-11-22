class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;
        unordered_map<int,vector<pair<int,int>> >adjList;

        for(auto it: times)
        {
            int u=it[0];
            int v=it[1];
            int time=it[2];
            adjList[u].push_back({v,time});
        }
        vector<int>dist(n+1,INT_MAX);
        pq.push({0,k});
        dist[k]=0;

        while(!pq.empty())
        {
            int T=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto it: adjList[node])
            {
                int nbrNode=it.first;
                if(T+it.second<dist[nbrNode])
                {
                    dist[nbrNode]=T+it.second;
                    pq.push({dist[nbrNode],nbrNode});
                }
            }
        }

        int maxi=INT_MIN;
        for(int i=1;i<n+1;i++)
        {
            maxi=max(maxi,dist[i]);
        }
        return maxi==INT_MAX?-1:maxi;
    }
};
