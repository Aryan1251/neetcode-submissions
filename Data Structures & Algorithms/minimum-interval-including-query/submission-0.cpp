class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int>v;
        map<pair<int,int>,int>mp;
        for(auto it: intervals)
        {
            mp[{it[0],it[1]}]=1;
        }
        for(auto it: queries)
        {
            int minLen=INT_MAX;
            for(auto val: mp)
            {
                auto &p=val.first;
                if(it>=p.first && it<=p.second)
                {
                    minLen=min(minLen,p.second-p.first+1);
                }
            }
            if(minLen==INT_MAX) minLen=-1;
            v.push_back(minLen);
        }
        return v;
    }
};
