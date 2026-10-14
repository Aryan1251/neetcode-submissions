class Solution {
    int Solve(int n)
    {
        if(n<0) return 0;
        if(n==0) return 1;

        int op1=Solve(n-1);
        int op2=Solve(n-2);

        return op1+op2;
    }
public:
    int climbStairs(int n) {
        return Solve(n);
    }
};
