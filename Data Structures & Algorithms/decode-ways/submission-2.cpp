class Solution {
    private:
    bool chkValid(char ch1,char ch2)
    {
        if(ch1=='1' && ch2<='9' || ch1=='2' && ch2<='6') return true;
        return false;
    }
    int Solve(string s,int index,vector<int>& dp)
    {
        if(index>=s.size()) return 1;
        if(s[index]=='0') return 0;
        if(dp[index]!=-1) return dp[index];

        int op1=Solve(s,index+1,dp);
        int op2=0;
        if(chkValid(s[index],s[index+1]) && index+2<=s.size())
        {
            op2=Solve(s,index+2,dp);
        }

        return dp[index]= op1+op2;
    }
public:
    int numDecodings(string s) {
        vector<int>dp(s.size()+1,-1);
        int ans=Solve(s,0,dp);
        return ans;
    }
};
