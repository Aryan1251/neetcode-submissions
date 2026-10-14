class Twitter {
public:
    int time;
    unordered_map<int,vector<pair<int,int>> >storeTweet;
    unordered_map<int,set<int> >mapFollower;
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        storeTweet[userId].push_back({time++,tweetId});
        
        return ;
    }
    vector<int> getNewsFeed(int userId) {
        auto v=storeTweet[userId];
        for(auto it: mapFollower[userId])
        {
            v.insert(v.end(),storeTweet[it].begin(),storeTweet[it].end());
        }
        priority_queue<pair<int,int> >pq;
        for(auto it: v)
        {
            pq.push({it.first,it.second});
        }
        int n=10;
        vector<int>ans;
        while(!pq.empty() && n--)
        {
            int id=pq.top().second;
            pq.pop();
            ans.push_back(id);
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId)
        mapFollower[followerId].insert(followeeId);
        return ;
    }
    
    void unfollow(int followerId, int followeeId) {
        auto &st=mapFollower[followerId];
        auto ind=st.find(followeeId);

        if(ind!=st.end())
        st.erase(ind);

        return ;
    }
};
