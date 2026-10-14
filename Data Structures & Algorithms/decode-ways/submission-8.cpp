class Solution {
    int Solve(string s,int index,vector<int>& dp)
    {
        if(index==s.size()-1)
        {
            if(s[index]>='1') return 1;
            else return 0;
        }
        if(index>=s.size()) return 1;
        if(dp[index]!=-1) return dp[index];

        //1 index up
        int cnt=0;

        if(s[index]>='1' && s[index]<='9')
        cnt+=Solve(s,index+1,dp);

        //2 index up
        if((s[index]=='1') || (s[index]=='2' && s[index+1]<='6'))
        cnt+=Solve(s,index+2,dp);

        return dp[index]= cnt;
    }
    int SolveTab(string s)
    {
        int n=s.size();
        vector<int>dp(n+1,0);
        if(s[n-1]>='1') dp[n-1]=1;
        dp[n]=1;
        for(int i=n-2;i>=0;i--)
        {
            //1 index up
            int cnt=0;
            if(s[i]>='1' && s[i]<='9')
            cnt+=dp[i+1]; //(s,index+1,dp);

           //2 index up
           if((s[i]=='1') || (s[i]=='2' && s[i+1]<='6'))
           cnt+=dp[i+2]; //Solve(s,index+2,dp);
           dp[i]= cnt;
        }
        return dp[0];
    }
public:
    int numDecodings(string s) {
        int ans=SolveTab(s);
        return ans;
    }
};
