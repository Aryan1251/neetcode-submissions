class Solution {
    int findInd(vector<int>& hand,int target,int s)
    {
        int e=hand.size()-1;
        while(s<=e)
        {
            int mid=(s+e)>>1;
            if(hand[mid]==target) return mid;
            else if(hand[mid]<target) s=mid+1;
            else e=mid-1;
        }
        return -1;
    }
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(),hand.end());
        int i=0,n=hand.size();

        unordered_map<int,int>mp;
        for(auto it: hand)
        {
            mp[it]++;
        }
        while(i<n)
        {
            int prev=hand[i];
            if(mp[prev]>0)
            {
                mp[prev]--;
                if(mp[prev]==0) mp.erase(prev);
            }
            else
            {
                i++;
                continue;
            }
            int index=i,cnt=groupSize;
            cnt-=1;
            while(cnt--)
            {
                int val=1+prev;
                auto ind=findInd(hand,val,index+1);
                if(ind<0) return false;
                if(mp[hand[ind]]>0)
                {
                    mp[hand[ind]]--;
                    if(mp[hand[ind]]==0) mp.erase(hand[ind]);
                }else return false;
                prev=val;
                index=ind;
            }
            i++;
        }
        for(auto it: hand)
        {
            if(mp[it]!=0) return false;
        }
        return true;
    }
};
