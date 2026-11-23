class Solution {
    int Solve(vector<int>& prices,vector<vector<int> >& dp,int buy,int ind)
    {
        if(ind>=prices.size()) return 0;
        if(dp[buy][ind]!=-1) return dp[buy][ind];

        if(buy)
        {
            int op1=-prices[ind] + Solve(prices,dp,!buy,ind+1);
            int op2=Solve(prices,dp,buy,ind+1);
            return dp[buy][ind]= max(op1,op2);
        }else
        {
            int op1=prices[ind] + Solve(prices,dp,!buy,ind+2);
            int op2=Solve(prices,dp,buy,ind+1);
            return dp[buy][ind]= max(op1,op2);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int> >dp(2,vector<int>(n+1,-1)); 
        int ans=Solve(prices,dp,1,0);
        return ans;
    }
};
