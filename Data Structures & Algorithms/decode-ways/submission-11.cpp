class Solution {
    int Solve(string s,vector<int>& dp, int ind)
    {
        if(ind>=s.size()) return 1;
        if(dp[ind]!=-1) return dp[ind];

        int op1=0,op2=0;

        if(s[ind]>='1' && s[ind]<='9')
        op1=Solve(s,dp,ind+1);

        if((s[ind]=='1' && s[ind+1]>='0' && s[ind+1]<='9') || (s[ind]=='2' && s[ind+1]>='0' && s[ind+1]<='6'))
        op2=Solve(s,dp,ind+2);

        return dp[ind]= op1+op2;
    }
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        int ans=Solve(s,dp,0);
        return ans;
    }
};
