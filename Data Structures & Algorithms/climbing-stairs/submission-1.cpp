class Solution {
    int Solve(int n,vector<int>& dp)
    {
        if(n==0 || n==1) return 1;
        if(dp[n]!=-1) return dp[n];

        return dp[n]= Solve(n-1,dp)+Solve(n-2,dp);
    }
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        int ans=Solve(n,dp);
        return ans;
    }
};
