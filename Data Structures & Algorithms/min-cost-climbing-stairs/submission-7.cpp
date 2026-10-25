class Solution {
    int Solve(vector<int>& cost,int ind)
    {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        dp[n]=0;

        for(int i=n;i>=ind;i--)
        {
            if(i==n) continue;

            int op1=cost[i] + dp[i+1];
            int op2=cost[i];
            if(i+2<n)
            op2+= dp[i+2];
    
            dp[i]= min(op1,op2);
        }
        return dp[ind];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int ans=min(Solve(cost,0),Solve(cost,1));
        return ans;
    }
};
