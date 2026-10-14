class Solution {
    int Solve(string text1,string text2,int i,int j,vector<vector<int> >& dp)
    {
        if(i>=text1.size() || j>=text2.size())
        {
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];

        int op=0;
        if(text1[i]==text2[j])
        {
            op=1+Solve(text1,text2,i+1,j+1,dp);
        }else{
            int op1=Solve(text1,text2,i+1,j,dp);
            int op2=Solve(text1,text2,i,j+1,dp);
            return dp[i][j]=max(op1,op2);
        }
        return dp[i][j]=op;
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int> >dp(n+1,vector<int>(m+1,-1));
       return Solve(text1,text2,0,0,dp);
    }
};
