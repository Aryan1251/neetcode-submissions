#define ll long long 

class Solution {
    double Solve(double x,ll n)
    {
        if(n==0) return 1;
        if(n==1) return x;

        double val=Solve(x,n/2);
        val*=val;

        if(n%2==1) val*=x;
        return val;
    }
public:
    double myPow(double x, int n) {
        bool flag=0;
        if(n<0)
        {
            flag=1;
            n=n*(-1);
        }
        double ans=Solve(x,(ll)n);
        if(flag) return 1/(double)ans;
        return ans;
    }
};
