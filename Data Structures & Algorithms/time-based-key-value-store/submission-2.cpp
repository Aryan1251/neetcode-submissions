class TimeMap {
public:
    map<string,vector<pair<string,int>> >mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value,timestamp});
        return ;
    }
    
    string get(string key, int timestamp) {
        auto vp=mp[key];
        int s=0,e=vp.size()-1;
        string ans;
        while(s<=e)
        {
            int mid=(s+e)>>1;
            string str=vp[mid].first;
            int time=vp[mid].second;
            if(time<=timestamp)
            {
                ans=str;
                s=mid+1;
            }else
            e=mid-1;
        }
        return ans;
    }
};
