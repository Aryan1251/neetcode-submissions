class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>> >mp;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
        return ;
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)==mp.end()) return "";

        auto& vp=mp[key];
        int n=vp.size();
        string ans;
        int s=0,e=n-1;
        while(s<=e)
        {
            int mid=(s+e)>>1;
            string val=vp[mid].second;
            int T=vp[mid].first;
            if(T<=timestamp)
            {
                ans=val;
                s=mid+1;
            }else
            e=mid-1;
        }
        return ans;
    }
};
