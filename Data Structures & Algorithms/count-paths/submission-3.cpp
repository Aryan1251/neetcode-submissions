class Solution {
    bool isValid(int i,int j,int n,int m)
    {
        if(i>=0 && i<n && j>=0 && j<m) return 1;
        return 0;
    }
    int Solve(int n,int m,vector<vector<int> >& dp,int i,int j)
    {
        if(i==n-1 && j==m-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];

        int op1=0,op2=0;
        //down
        if(isValid(i+1,j,n,m))
        op1=Solve(n,m,dp,i+1,j);

        //right
        if(isValid(i,j+1,n,m))
        op2=Solve(n,m,dp,i,j+1);

        return dp[i][j]= op1+op2;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> >dp(m+1,vector<int>(n+1,-1));
        return Solve(m,n,dp,0,0);
    }
};
