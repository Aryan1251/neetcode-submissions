class Solution {
    bool isValid(int i,int j,int m,int n)
    {
        if(i>=0 && j>=0 && i<m && j<n) return 1;
        return 0;
    }
    int Solve(int m,int n,vector<vector<int> >& dp,int i,int j)
    {
        if(i==m-1 && j==n-1) return 1;
        if(i>=m || j>=n) return 0;

        int op1=0,op2=0;
        if(isValid(i+1,j,m,n))
        op1=Solve(m,n,dp,i+1,j);

        if(isValid(i,j+1,m,n))
        op2=Solve(m,n,dp,i,j+1);

        return dp[i][j]= op1+op2;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> >dp(m+1,vector<int>(n+1,-1));
        int totalPath=Solve(m,n,dp,0,0);
        return totalPath;
    }
};
