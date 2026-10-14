class Solution {
    int minDisSolve(string s1,string s2,vector<vector<int> >& dp,int i,int j)
    {
        if(i>=s1.size() && j>=s2.size()) return 0;
        if(i>=s1.size()) return s2.size()-j;
        if(j>=s2.size()) return s1.size()-i;
        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j])
        return dp[i][j]= minDisSolve(s1,s2,dp,i+1,j+1);
        else
        {
            int op1=1+minDisSolve(s1,s2,dp,i,j+1);
            int op2=1+minDisSolve(s1,s2,dp,i+1,j);
            int op3=1+minDisSolve(s1,s2,dp,i+1,j+1);
            return dp[i][j]= min(op1,min(op2,op3));
        }
    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int> >dp(n+1,vector<int>(m+1,-1));
        int dis=minDisSolve(word1,word2,dp,0,0);
        return dis;
    }
};
