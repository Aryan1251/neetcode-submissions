class Solution {
    double Solve(double a,int n)
    {
        if(n==0) return 1;

        double ans=Solve(a,n/2);

        if(n%2==0) ans*=ans;
        else ans=ans*ans*a;

        return ans;
    }
public:
    double myPow(double x, int n) {
        bool flag=0;
        if(n<0) {flag=1;n*=-1;}
        double ans=Solve(x,n);
        return flag?1/(double)ans:ans;
    }
};
