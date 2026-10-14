class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int>mp;
        while(1)
        {
            int sum=0;
            while(n)
            {
                int digit=n%10;
                sum+=digit*digit;
                n/=10;
            }
            if(sum==1) return true;
            if(mp.find(sum)!=mp.end()) return false;
            mp[sum]=1;
            n=sum;
        }
        return false;
    }
};
