class Solution {
    double Solve(double a,int b)
    {
        if(b==0) return 1;
        
        double val=Solve(a,b/2);

        if(b%2==0)
        return val*val;
        else 
        return val*val*a;
    }
public:
    double myPow(double x, int n) {
        double ans=Solve(x,n);
        if(n<0)
        {
            ans=1/(double)ans;
        }
        return ans;
    }
};
