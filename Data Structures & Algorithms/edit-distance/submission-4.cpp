class Solution {
    int solveTab(string &word1,string &word2){
        int n=word1.size();
        int m=word2.size();
        vector<vector<int> >dp(n+1,vector<int>(m+1,0));
        for(int j=0;j<=m;j++)
        {
            dp[n][j]=m-j;
        }
        for(int i=0;i<=n;i++)
        {
            dp[i][m]=n-i;
        }

        for(int i=n;i>=0;i--)
        {
            for(int j=m;j>=0;j--)
            {
                if(i==n || j==m) continue;
                int op=0;
                if(word1[i]==word2[j])
                op=dp[i+1][j+1]; //Solve(word1,word2,i+1,j+1,dp);
                else
                {
                    int op1=1+dp[i][j+1]; //Solve(word1,word2,i,j+1,dp); //insert
                    int op2=1+dp[i+1][j+1]; //(word1,word2,i+1,j+1,dp); //replace
                    int op3=1+dp[i+1][j]; //Solve(word1,word2,i+1,j,dp);//delete
                    op= min(op1,min(op2,op3));
                }
                dp[i][j]=op;
            }
        }
        return dp[0][0];
    }
public:
    int minDistance(string word1, string word2) {
       int ans= solveTab(word1,word2);
       return ans;
    }
};
