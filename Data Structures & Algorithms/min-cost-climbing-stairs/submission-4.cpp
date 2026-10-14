class Solution {
    int Solve(vector<int>& cost,vector<int>& dp,int ind)
    {
        if(ind>=cost.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];

        int op1=cost[ind]+Solve(cost,dp,ind+1);
        int op2=cost[ind]+Solve(cost,dp,ind+2);

        return dp[ind]= min(op1,op2);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        int op1=Solve(cost,dp,0);
        dp.clear();
        int op2=Solve(cost,dp,1);
        return min(op1,op2);
    }
};
