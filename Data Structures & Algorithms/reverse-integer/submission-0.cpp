class Solution {
public:
    int reverse(int x) {
        bool flag=x<0 ? 1 : 0;
        x=abs(x);
        int rev=0;
        while(x)
        {
            int lastDigit=x%10;
            if(rev>= (INT_MAX/10))
            return 0;
            rev=rev*10+lastDigit;
            x/=10;
        }
        if(flag) return -1*rev;
        return rev;
    }
};
