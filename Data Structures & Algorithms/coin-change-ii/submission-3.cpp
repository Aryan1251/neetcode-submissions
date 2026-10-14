class Solution {
    int changeSolve(vector<int>& coins,vector<vector<int> >& dp,int amount,int ind)
    {
        if(amount==0) return 1;
        if(ind>=coins.size()) return 0;
        if(dp[amount][ind]!=-1) return dp[amount][ind];

        int op1=0,op2=0;
        if(amount>=coins[ind])
        op1=changeSolve(coins,dp,amount-coins[ind],ind);

        op2=changeSolve(coins,dp,amount,ind+1);

        return dp[amount][ind]= op1+op2;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int> >dp(amount+1,vector<int>(n+1,-1));
        int ans=changeSolve(coins,dp,amount,0);
        return ans;
    }
};
