class Solution {
    private:
    bool isPossible(vector<int>& piles,long long speed,long long h)
    {
        long long cnt=0,n=piles.size();
        for(int i=0;i<n;i++)
        {
            if(speed==0) return 0;
            int t=ceil(piles[i]/(double)speed);
            cnt=(long long)cnt+(long long)t;
            if(cnt>h) return false;
        }

        return cnt<=h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        long long s=0,maxi=0;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,(long long)piles[i]);
        }
        long long ans=-1,e=maxi;
        while(s<=e)
        {
            long long mid=s+(e-s)/2;
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
