class Solution {
    bool isPossible(vector<int>& piles,long long mid,int hour)
    {
        if(mid==0) return false;
        cout<<mid<<" ";
        long long cnt=0;
        for(int i=0;i<piles.size();i++)
        {
            cnt+=ceil((double)piles[i]/mid);
            cout<<ceil((double)piles[i]/mid);
            if(cnt>hour) return false;
        }
        cout<<endl;
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long sum=0;
        int n=piles.size();
        for(int i=0;i<n;i++)
        {
            sum+=piles[i];
        }
        long long s=0,e=sum,ans=-1;
        while(s<=e)
        {
            long long mid=(s+e)>>1;
            if(isPossible(piles,mid,h))
            {
                ans=mid;
                e=mid-1;
            }else
            {
                s=mid+1;
            }
        }
        return (int)ans;
    }
};
