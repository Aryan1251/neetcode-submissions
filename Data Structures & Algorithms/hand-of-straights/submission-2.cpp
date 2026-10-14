class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
       unordered_map<int,int>mp;
       int mini=INT_MAX;
       for(auto num: hand)
       {
        mp[num]++;
        mini=min(mini,num);
       }
       while(1)
       {
        int k=groupSize;
        int val=mini;
        if(mp.empty()) return true;
        if(mp.find(mini)==mp.end())
        {
            mini+=1;
            continue;
        }
        while(k--)
        {
            if(mp.find(val)==mp.end()) return false;
            mp[val]--;
            if(mp[val]==0) mp.erase(val);
            val=val+1;
        }
        if(mp.find(mini)!=mp.end()) continue;
        else mini+=1;
       }
       return false;
    }
};
