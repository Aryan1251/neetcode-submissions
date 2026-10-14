#define ll long long

class Solution {
    bool isPossible(vector<int>& piles,ll mid,int h)
    {
        if(mid==0) return 0;
        ll n=piles.size(),time=0;
        for(int i=0;i<n;i++)
        {
            ll val=ceil((double)piles[i]/(double)mid);
            time=(ll)time+(ll)val;
        }
        return time<=h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        ll s=0,maxi=INT_MIN,e=-1;

        for(int i=0;i<n;i++)
        maxi=max(maxi,(ll)piles[i]);

        e=maxi;
        ll ans=-1;
        while(s<=e)
        {
            ll mid=(s+e)>>1;
            if(isPossible(piles,mid,h))
            {
                ans=mid;
                e=mid-1;
            }else
            s=mid+1;
        }
        return (int)ans;
    }
};
