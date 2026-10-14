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
        else
        {
            vector<pair<string,int> >vp=mp[key];
            int s=0,e=vp.size()-1;
            string ans;
            while(s<=e)
            {
                int mid=(s+e)>>1;
                if(vp[mid].second>timestamp) e=mid-1;
                else
                {
                    ans=vp[mid].first;
                    s=mid+1;
                }
            }
            return ans;
        }
        return "";
    }
};
