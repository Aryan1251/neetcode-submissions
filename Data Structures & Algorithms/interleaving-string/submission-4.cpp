class Solution {
    bool Solve(string s1,string s2,string s3,int i,int j,int k,vector<vector<vector<int>> >& dp)
    {
        if(i>=s1.size() && j>=s2.size() && k>=s3.size()) return true;
        if(dp[i][j][k]!=-1) return dp[i][j][k];

        bool op1=false,op2=false;
        if(i<s1.size() && s1[i]==s3[k])
        op1= Solve(s1,s2,s3,i+1,j,k+1,dp);

        if(j<s2.size() && s2[j]==s3[k])
        op2= Solve(s1,s2,s3,i,j+1,k+1,dp);

        return dp[i][j][k]= op1|op2;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        int k=s3.size();
        vector<vector<vector<int>> >dp(n+1,vector<vector<int> >(m+1,vector<int>(k+1,-1)));
        bool ans=Solve(s1,s2,s3,0,0,0,dp);
        return ans;
    }
};
