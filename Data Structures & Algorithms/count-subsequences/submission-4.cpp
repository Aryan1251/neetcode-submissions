class Solution {
    int solveTab(string& s, string& t)
    {
        int n=s.size();
        int m=t.size();
        vector<vector<int> >dp(n+1,vector<int>(m+1,-1));

        for(int j=0;j<=m;j++)
        dp[n][j]=0;

        for(int i=0;i<=n;i++)
        dp[i][m]=1;

        for(int i=n;i>=0;i--)
        {
            for(int j=m;j>=0;j--)
            {
                if(i==n || j==m) continue;
                int op1=0;
                if(s[i]==t[j])
                op1=dp[i+1][j+1]; //Solve(s,t,i+1,j+1);
        
                int op2=dp[i+1][j]; //Solve(s,t,i+1,j);
        
                dp[i][j]= op1+op2;
            }
        }
        return dp[0][0];
    }
public:
    int numDistinct(string s, string t) {
        int ans=solveTab(s,t);
        return ans;
    }
};
