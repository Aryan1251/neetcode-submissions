class Solution {
public:
    bool isHappy(int n) {
        
        int val=n;
        unordered_map<int,int>mp;
        while(1)
        {
            int sum=0;
            while(val)
            {
                int lastDigit=val%10;
                val/=10;
                sum+=(lastDigit*lastDigit);
            }
            if(sum==1) return 1;
            if(mp[sum]>0) return false;
            mp[sum]=1;
            val=sum;
        }
        return 0;
    }
};
