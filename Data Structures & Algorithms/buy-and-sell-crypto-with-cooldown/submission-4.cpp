class Solution {
    int Solve(vector<int>& prices,vector<vector<int> >& dp,int ind,int buy)
    {
        if(ind>=prices.size()) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];

        if(buy)
        {
            int op1=-prices[ind] + Solve(prices,dp,ind+1,!buy);
            int op2=Solve(prices,dp,ind+1,buy);
            return dp[ind][buy]= max(op1,op2);
        }else
        {
            int op1=prices[ind]+Solve(prices,dp,ind+2,!buy);
            int op2=Solve(prices,dp,ind+1,buy);
            return dp[ind][buy]= max(op1,op2);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int> >dp(n+1,vector<int>(2,-1));
        int ans=Solve(prices,dp,0,1);
        return ans;
    }
};
