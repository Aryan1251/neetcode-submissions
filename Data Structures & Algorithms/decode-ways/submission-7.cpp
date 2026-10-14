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
public:
    int numDecodings(string s) {
        vector<int>dp(s.size()+1,-1);
        int ans=Solve(s,0,dp);
        return ans;
    }
};
