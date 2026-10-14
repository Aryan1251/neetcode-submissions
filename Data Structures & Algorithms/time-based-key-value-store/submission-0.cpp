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
        if(mp.find(key)==mp.end()) return "";
        auto v=mp[key];
        int s=0,e=v.size()-1;
        string ans;
        while(s<=e)
        {
            int mid=(s+e)>>1;
            if(v[mid].second<=timestamp)
            {
                ans=v[mid].first;
                s=mid+1;
            }else
            {
                e=mid-1;
            }
        }
        return ans;
    }
};
