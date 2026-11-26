class Solution {
    bool Solve(string& s1,string& s2,string& s3,vector<vector<vector<int> > >& dp,int i,int j,int k)
    {
        if(k>=s3.size())
        {
            if(i>=s1.size() && j>=s2.size()) return 1;
            return 0;
        }
        if(i>=s1.size() && j>=s2.size()) return 0;
        
        bool ans=false;
        if(i<s1.size() && s1[i]==s3[k])
        ans=ans|Solve(s1,s2,s3,dp,i+1,j,k+1);

        if(j<s2.size() && s2[j]==s3[k])
        ans=ans|Solve(s1,s2,s3,dp,i,j+1,k+1);

        return dp[i][j][k]= ans;
    }
    int solveTab(string& s1,string& s2,string& s3)
    {
        int n=s1.size();
        int m=s2.size();
        int l=s3.size();
        vector<vector<vector<bool> > >dp(n+1,vector<vector<bool> >(m+1,vector<bool>(l+1,false)));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                dp[i][j][l]=0;
            }
        }
        dp[n][m][l]=1;

        for(int k=0;k<l;k++)
        dp[n][m][k]=0;

        for(int i=n;i>=0;i--)
        {
            for(int j=m;j>=0;j--)
            {
                for(int k=l;k>=0;k--)
                {
                    if(i==n && j==m && k==l) continue;
                    if(i==n && j==m) continue;
                    if(k==l) continue;
                    bool ans=false;
                    if(i<s1.size() && s1[i]==s3[k])
                    ans=ans|dp[i+1][j][k+1]; //Solve(s1,s2,s3,dp,i+1,j,k+1);
            
                    if(j<s2.size() && s2[j]==s3[k])
                    ans=ans|dp[i][j+1][k+1]; //Solve(s1,s2,s3,dp,i,j+1,k+1);
            
                    dp[i][j][k]= ans;
                }
            }
        }
        return dp[0][0][0];
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        // int n=s1.size();
        // int m=s2.size();
        // int l=s3.size();
        // vector<vector<vector<int> > >dp(n+1,vector<vector<int> >(m+1,vector<int>(l+1,-1)));
        return solveTab(s1,s2,s3);
    }
};
