class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>> >adj;
        for(auto it: times)
        {
            int u=it[0];
            int v=it[1];
            int T=it[2];
            adj[u].push_back({v,T});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;
        vector<int>Time(n+1,INT_MAX);
        pq.push({0,k});
        Time[k]=0;
        while(!pq.empty())
        {
            auto T=pq.top().first;
            auto node=pq.top().second;
            pq.pop();

            for(auto it: adj[node])
            {
                if(T+it.second<Time[it.first])
                {
                    Time[it.first]=T+it.second;
                    pq.push({T+it.second,it.first});
                }
            }
        }
        int maxi=0;
        for(int i=1;i<n+1;i++)
        {
            maxi=max(maxi,Time[i]);
        }
        return maxi==INT_MAX?-1:maxi;
    }
};
