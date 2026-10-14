class Solution {
    int Solve(string s,string t,int i,int j,vector<vector<int> >& dp)
    {
        if(j>=t.size()) return 1;

        if(i>=s.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int op1=0;
        if(s[i]==t[j])
        op1=Solve(s,t,i+1,j+1,dp);

        int op2=Solve(s,t,i+1,j,dp);

        return dp[i][j]= op1+op2;
    }
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int> >dp(n+1,vector<int>(m+1,-1));
        int ans=Solve(s,t,0,0,dp);
        return ans;
    }
};
