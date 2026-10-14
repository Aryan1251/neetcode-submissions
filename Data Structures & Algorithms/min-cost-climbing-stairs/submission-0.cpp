class Solution {
    int Solve(vector<int>& cost,int index,vector<int>& dp)
    {
        if(index>=cost.size()) return 0;
        if(dp[index]!=-1) return dp[index];

        int op1=cost[index]+Solve(cost,index+1,dp);
        int op2=cost[index]+Solve(cost,index+2,dp);

        return dp[index]= min(op1,op2);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp1(n+1,-1),dp2(n+1,-1);
        
        int op1=Solve(cost,0,dp1);
        int op2=Solve(cost,1,dp2);

        return min(op1,op2);
    }
};
