class Solution {
    int solveTab(vector<int>& coins,int amount)
    {
        int n=coins.size();
        vector<vector<int> >dp(n+1,vector<int>(amount+1,-1));
        for(int j=0;j<=amount;j++)
        {
            dp[n][j]=0;
        }
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        for(int i=n;i>=0;i--)
        {
            for(int j=0;j<=amount;j++)
            {
                if(i==n || amount==0) continue;
                int op1=0;
                if(coins[i]<=j)
                op1=dp[i][j-coins[i]]; //Solve(coins,index,amount-coins[index],dp);
                int op2=dp[i+1][j]; //Solve(coins,index+1,amount,dp);
        
                dp[i][j]=op1+op2;
            }
        }
        return dp[0][amount];
    }
public:
    int change(int amount, vector<int>& coins) {
        int ans=solveTab(coins,amount);
        return ans;
    }
};
