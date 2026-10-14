class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0) return false;
        sort(hand.begin(),hand.end());
        unordered_map<int,int>mp;

        for(auto num: hand)
        {
            mp[num]++;
        }

        for(int i=0;i<hand.size();i++)
        {
            if(mp.find(hand[i])!=mp.end())
            {
                int k=groupSize;
                int val=hand[i]+1;
                mp[hand[i]]--;
                if(mp[hand[i]]==0) mp.erase(hand[i]);
                k--;
                while(k--)
                {
                    if(mp.find(val)==mp.end()) return false;
                    mp[val]--;
                    if(mp[val]==0) mp.erase(val);
                    val+=1;
                }
            }
        }
        return true;
    }
};
