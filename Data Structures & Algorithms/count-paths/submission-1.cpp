class Solution {
    int Solve(int i,int j,int m,int n,vector<vector<int> >& dp)
    {
        if(i==m-1 && j==n-1) return 1;
        if(i>=m || j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int op1=Solve(i+1,j,m,n,dp);
        int op2=Solve(i,j+1,m,n,dp);

        return dp[i][j]=op1+op2;
    }
    int solveTab(int m,int n)
    {
        vector<vector<int> >dp(m+1,vector<int>(n+1,0));
        dp[m-1][n-1]=1;
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(i==m-1 && j==n-1) continue;
                int op1=dp[i+1][j]; //Solve(i+1,j,m,n,dp);
                int op2=dp[i][j+1]; //Solve(i,j+1,m,n,dp);
        
                dp[i][j]=op1+op2;
            }
        }
        return dp[0][0];
    }
public:
    int uniquePaths(int m, int n) {
        int ans=solveTab(m,n);
        return ans;
    }
};
