class Solution {
    int Solve(string &s,string &t,int ind1,int ind2,vector<vector<int> >& dp)
    {
        if(ind1>=s.size() || ind2>=t.size()) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];

        int ans=0;
        if(s[ind1]==t[ind2])
        {
            ans=1+Solve(s,t,ind1+1,ind2+1,dp);
        }else
        {
            int op1=Solve(s,t,ind1+1,ind2,dp);
            int op2=Solve(s,t,ind1,ind2+1,dp);
            return dp[ind1][ind2]= max(op1,op2);
        }
        return dp[ind1][ind2]= ans;
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int> >dp(n1+1,vector<int>(n2+1,-1));
        int ans=Solve(text1,text2,0,0,dp);
        return ans;
    }
};
