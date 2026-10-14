class Solution {
    int Solve(vector<int>& coins,int amount,int index,vector<vector<int> >& dp)
    {
        if(index>=coins.size())
        {
            return INT_MAX;
        }
        if(amount==0) return 0;
        if(dp[amount][index]!=-1) return dp[amount][index];
        
        int op1=INT_MAX,op2=INT_MAX;
        if(coins[index]<=amount)
        {
            op1=Solve(coins,amount-coins[index],index,dp);
            if(op1!=INT_MAX)
            op1+=1;
        }

        op2=Solve(coins,amount,index+1,dp);

        return dp[amount][index]=min(op1,op2);
    }
    int solveTab(vector<int>& coins,int amount)
    {
        int n=coins.size();
        vector<vector<int> >dp(amount+1,vector<int>(n+1,-1));
        for(int i=0;i<=amount;i++)
        dp[i][n]=INT_MAX;

        for(int j=0;j<=n;j++)
        dp[0][j]=0;

        for(int i=0;i<=amount;i++)
        {
            for(int j=n;j>=0;j--)
            {
                if(j==n || i==0) continue;
                int op1=INT_MAX,op2=INT_MAX;
                if(coins[j]<=i)
                {
                    op1=dp[i-coins[j]][j]; //Solve(coins,amount-coins[index],index,dp);
                    if(op1!=INT_MAX)
                    op1+=1;
                }
                op2=dp[i][j+1]; //Solve(coins,amount,index+1,dp);
                dp[i][j]=min(op1,op2);
            }
        }
        return dp[amount][0];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int ans=solveTab(coins,amount);
        return ans==INT_MAX?-1:ans;
    }
};
