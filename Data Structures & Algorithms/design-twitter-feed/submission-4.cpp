class Twitter {
public:
    int time;
    unordered_map<int,set<int> >mp;
    unordered_map<int,vector<pair<int,int>> >vp;
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        vp[userId].push_back({time,tweetId});
        time+=1;
        return ;
    }
    bool static myComp(pair<int,int>& a,pair<int,int>& b)
    {
        return a.first>b.first;
    }
    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int> >ans;
        vector<int>allId;
        allId.push_back(userId);
        for(auto it: mp[userId])
        {
            allId.push_back(it);
        }
        for(auto id: allId)
        {
            auto &v=vp[id];
            for(auto tweetId: v)
            {
                ans.push_back({tweetId.first,tweetId.second});
            }
        }
        sort(ans.begin(),ans.end(),myComp);
        vector<int>v;
        for(auto it: ans)
        {
            v.push_back(it.second);
            if(v.size()==10) break;
        }
        return v;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId)
        mp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        mp[followerId].erase(followeeId);
        return ;
    }
};
