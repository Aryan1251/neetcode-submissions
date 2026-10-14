class Solution {
    int Solve(vector<int>& coins,int ind,int target,vector<vector<int> >& dp)
    {
        if(target==0) return 1;
        if(ind>=coins.size()) return 0;
        if(dp[ind][target]!=-1) return dp[ind][target];

        int op1=0;
        if(coins[ind]<=target)
        op1=Solve(coins,ind,target-coins[ind],dp);

        int op2=Solve(coins,ind+1,target,dp);

        return dp[ind][target]= op1+op2;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int> >dp(n+1,vector<int>(amount+1,-1));
        int ans=Solve(coins,0,amount,dp);
        return ans;
    }
};
