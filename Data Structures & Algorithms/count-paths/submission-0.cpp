class Solution {
    int Solve(int i,int j,int m,int n)
    {
        if(i==m-1 && j==n-1) return 1;
        if(i>=m || j>=n) return 0;

        int op1=Solve(i+1,j,m,n);
        int op2=Solve(i,j+1,m,n);

        return op1+op2;
    }
public:
    int uniquePaths(int m, int n) {
        int ans=Solve(0,0,m,n);
        return ans;
    }
};
