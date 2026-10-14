class Solution {
    int Solve(int n)
    {
        if(n<0) return 0;
        if(n==1 || n==0) return 1;

        int op1=Solve(n-1);
        int op2=Solve(n-2);

        return op2+op1;
    }
public:
    int climbStairs(int n) {
        int ans=Solve(n);
        return ans;
    }
};
