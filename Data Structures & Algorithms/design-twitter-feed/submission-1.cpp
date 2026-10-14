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
    bool static myComp(pair<int,int>& a,pair<int,int>& b)
    {
        return a.first>b.first;
    }
    vector<int> getNewsFeed(int userId) {
        auto v=storeTweet[userId];
        for(auto it: mapFollower[userId])
        {
            v.insert(v.end(),storeTweet[it].begin(),storeTweet[it].end());
        }
        sort(v.begin(),v.end(),myComp);
        vector<int>ans;
        int n=v.size();
        for(int i=0;i<min(10,n);i++)
        {
            ans.push_back(v[i].second);
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
