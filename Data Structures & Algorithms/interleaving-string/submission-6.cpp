class Solution {
    bool Solve(string s1,string s2,string s3,vector<vector<vector<int>> >& dp, int i,int j,int k)
    {
        if(i>=s1.size() && j>=s2.size() && k>=s3.size()) return 1;
        if(k>=s3.size()) return 0;
        if(dp[i][j][k]!=-1) return dp[i][j][k];

        bool op1=0,op2=0;
        if(s1[i]==s3[k])
        op1=Solve(s1,s2,s3,dp,i+1,j,k+1);

        if(s2[j]==s3[k])
        op2=Solve(s1,s2,s3,dp,i,j+1,k+1);

        return dp[i][j][k]= op1|op2;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        int k=s3.size();
        vector<vector<vector<int>> >dp(n+1,vector<vector<int> >(m+1,vector<int>(k+1,-1)));

        bool ans=Solve(s1,s2,s3,dp,0,0,0);
        return ans;
    }
};
