class Twitter {
public:
    map<int,set<int> >followUser;
    map<int,vector<pair<int,int>> >mp;
    int time; 
    Twitter() {
        time=1;
    }
    
    void postTweet(int userId, int tweetId) {
        mp[userId].push_back({tweetId,time});
        time++;
        return ;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int> >pq;
        vector<int>allIds;
        for(auto id: followUser[userId])
        {
            allIds.push_back(id);
        }
        allIds.push_back(userId);
        for(int i=0;i<allIds.size();i++)
        {
            int id=allIds[i];
            for(auto it: mp[id])
            {
                pq.push({it.second,it.first});
            }
        }
        int cnt=10;
        vector<int>ans;
        while(!pq.empty() && cnt--)
        {
            auto id=pq.top().second;
            pq.pop();
            ans.push_back(id);
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId==followeeId) return ;
        followUser[followerId].insert(followeeId);
        return ;
    }
    
    void unfollow(int followerId, int followeeId) {
        followUser[followerId].erase(followeeId);
        return ;
    }
};
