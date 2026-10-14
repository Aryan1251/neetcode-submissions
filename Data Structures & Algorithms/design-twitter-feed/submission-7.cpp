class Twitter {
public:
    map<int,set<int> >followMap;
    map<int,vector<pair<int,int>> >mp;
    int time;
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        mp[userId].push_back({tweetId,time+1});
        time+=1;
    }
    bool static myComp(pair<int,int>&a,pair<int,int>&b)
    {
        return a.first>b.first;
    }
    vector<int> getNewsFeed(int userId) {
        vector<int>friendsId;
        friendsId.push_back(userId);
        for(auto it: followMap[userId])
        {
            friendsId.push_back(it);
        }
        vector<pair<int,int> >v;
        for(auto id: friendsId)
        {
            for(auto vp:mp[id])
            {
                v.push_back({vp.second,vp.first});
            }
        }
        vector<int>ans;
        sort(v.begin(),v.end(),myComp);
        int n=v.size();
        for(int i=0;i<min(10,n);i++)
        ans.push_back(v[i].second);

        return ans;

    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId)
        followMap[followerId].insert(followeeId);
        return ;
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
        return ;
    }
};
