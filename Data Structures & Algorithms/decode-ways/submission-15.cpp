class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        dp[n]=1;

        for(int i=n;i>=0;i--)
        {
            if(i==n) continue;
            int op1=0,op2=0,op3=0;
            if(s[i]>='1')
            {
                op1=dp[i+1];
                if(i+1<s.size() && s[i]=='2' && s[i+1]<='6') 
                op2=dp[i+2]; 
    
                if(s[i]=='1' && i+2<=s.size()) op3=dp[i+2];
            }
            dp[i]= op1+op2+op3;
        }
        return dp[0];
    }
};
