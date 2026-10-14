class Solution {
public:
    double myPow(double x, int n) {
        
        double fact=1;
        bool flag=n<0?1:0;
        if(flag) n*=(-1);
        for(int i=0;i<n;i++)
        {
            fact*=x;
        }
        if(flag)
        {
            fact=1/(double)fact;
        }
        return fact;
    }
};
