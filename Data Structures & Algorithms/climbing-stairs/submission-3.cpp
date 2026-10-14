class Solution {
    int Solve(int n,vector<int>& dp)
    {
        if(n<0) return 0;
        if(n==1 || n==0) return 1;
        if(dp[n]!=-1) return dp[n];

        int op1=Solve(n-1,dp);
        int op2=Solve(n-2,dp);

        return dp[n]= op2+op1;
    }
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        int ans=Solve(n,dp);
        return ans;
    }
};
