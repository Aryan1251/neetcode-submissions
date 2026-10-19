class Solution {
    int Solve(vector<int>& coins,int amt,vector<vector<int> >& dp,int ind)
    {
        if(amt==0) return 1;
        if(ind>=coins.size()) return 0;
        if(dp[amt][ind]!=-1) return dp[amt][ind];

        int op1=0;
        if(coins[ind]<=amt)
        op1=Solve(coins,amt-coins[ind],dp,ind);

        int op2=Solve(coins,amt,dp,ind+1);

        return dp[amt][ind]=op1+op2;
    }
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int> >dp(amount+1,vector<int>(coins.size()+1,-1));
        int ans=Solve(coins,amount,dp,0);
        return ans;
    }
};
