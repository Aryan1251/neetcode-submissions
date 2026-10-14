class Solution {
    private:
    bool Solve(string s,int index,unordered_map<string,int>& mp,vector<int>& dp)
    {
        if(index>=s.size()) return true;
        if(dp[index]!=-1) return dp[index];

        string str;
        bool op1=false;
        for(int i=index;i<s.size();i++)
        {
            str+=s[i];
            if(mp.find(str)!=mp.end())
            {
                op1=op1 | Solve(s,i+1,mp,dp);
            }
        }
        return dp[index]= op1;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int>mp;
        for(auto str: wordDict)
        {
            mp[str]=1;
        }
        vector<int>dp(s.size()+1,-1);
        return Solve(s,0,mp,dp);
    }
};
