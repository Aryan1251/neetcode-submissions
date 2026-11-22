class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;
        unordered_map<int,vector<pair<int,int>> >adjList;
        set<pair<int,int> >st;

        for(auto it: times)
        {
            int u=it[0];
            int v=it[1];
            int time=it[2];
            adjList[u].push_back({v,time});
        }
        vector<int>dist(n+1,INT_MAX);
        st.insert({0,k});
        dist[k]=0;

        while(!st.empty())
        {
            auto topElement=st.begin();

            int T=topElement->first;
            int node=topElement->second;

            st.erase(topElement);

            for(auto it: adjList[node])
            {
                int nbrNode=it.first;
                if(T+it.second<dist[nbrNode])
                {
                    if(st.find({dist[nbrNode],nbrNode})!=st.end())
                    {
                        auto ind=st.find({dist[nbrNode],nbrNode});
                        st.erase(ind);
                    }
                    dist[nbrNode]=T+it.second;
                    st.insert({dist[nbrNode],nbrNode});
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
