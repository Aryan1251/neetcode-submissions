class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1,INT_MAX);
        unordered_map<int,vector<pair<int,int>> >adj;
        for(auto it: times)
        {
            int u=it[0];
            int v=it[1];
            int dist=it[2];
            adj[u].push_back({v,dist});
        }
        dist[k]=0;
        set<pair<int,int> >st;
        st.insert({0,k});
        while(!st.empty())
        {
            auto topEle=st.begin();
            auto p=*topEle;

            int D=p.first;
            int node=p.second;

            st.erase(topEle);

            for(auto it: adj[node])
            {
                int v=it.first;
                int d=it.second;
                if(D+d<dist[v])
                {
                    auto ind=st.find({dist[v],v});
                    if(ind!=st.end()) st.erase(ind);

                    dist[v]=D+d;
                    st.insert({dist[v],v});
                }
            }
        }
        int ans=0;
        for(int node=1;node<=n;node++)
        {
            ans=max(ans,dist[node]);
        }
        return ans==INT_MAX?-1:ans;
    }
};
