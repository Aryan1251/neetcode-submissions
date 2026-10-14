class Solution {
    // int Solve(string s1,string s2,vector<vector<int> >& dp,int i,int j)
    // {
    //     //base case
    //     if(i>=s1.size() || j>=s2.size()) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];

    //     if(s1[i]==s2[j])
    //     return dp[i][j]= 1+Solve(s1,s2,dp,i+1,j+1);
    //     else
    //     {
    //         int op1=Solve(s1,s2,dp,i+1,j);
    //         int op2=Solve(s1,s2,dp,i,j+1);
    //         return dp[i][j]= max(op1,op2);
    //     }
    // }
    int Solve(string s1,string s2)
    {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int> >dp(n+1,vector<int>(m+1,0));
        for(int j=0;j<m;j++)
        dp[s1.size()][j]=0;

        for(int i=0;i<n;i++)
        dp[i][s2.size()]=0;

        for(int i=n;i>=0;i--)
        {
            for(int j=m;j>=0;j--)
            {
                if(i>=n || j>=m) continue;

                if(s1[i]==s2[j])
                dp[i][j]= 1+dp[i+1][j+1]; //Solve(s1,s2,dp,i+1,j+1);
                else
                {
                    int op1=dp[i+1][j]; //Solve(s1,s2,dp,i+1,j);
                    int op2=dp[i][j+1]; //Solve(s1,s2,dp,i,j+1);
                    dp[i][j]= max(op1,op2);
                }
            }
        }
        return dp[0][0];
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int lcs=Solve(text1,text2);
        return lcs;
    }
};
