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
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int> >dp(amount+1,vector<int>(coins.size()+1,-1));
        int ans=Solve(coins,amount,0,dp);
        return ans==INT_MAX?-1:ans;
    }
};
