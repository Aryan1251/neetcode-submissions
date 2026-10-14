class Solution {
    int Solve(vector<int>& prices,int buy,int ind,vector<vector<int> >& dp)
    {
        if(ind>=prices.size()) return 0;
        if(dp[buy][ind]!=-1) return dp[buy][ind];

        if(buy)
        {
            int op1=-prices[ind]+Solve(prices,!buy,ind+1,dp);
            int op2=Solve(prices,buy,ind+1,dp);
            return dp[buy][ind]= max(op1,op2);
        }else
        {
            int op1=prices[ind]+Solve(prices,!buy,ind+2,dp);
            int op2=Solve(prices,buy,ind+1,dp);
            return dp[buy][ind]= max(op1,op2);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int> >dp(2,vector<int>(n+1,-1));
        int ans=Solve(prices,1,0,dp);
        return ans;
    }
};
