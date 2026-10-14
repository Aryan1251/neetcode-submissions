class Solution {
    bool Solve(string s,unordered_map<string,int>& mp,int index,vector<int>& dp)
    {
        if(index>=s.size()) return true;
        if(dp[index]!=-1) return dp[index];

        string str;
        bool ans=false;
        for(int i=index;i<s.size();i++)
        {
            str+=s[i];
            if(mp.find(str)!=mp.end())
            {
                ans=ans | Solve(s,mp,i+1,dp);
            }
        }
        return dp[index]=ans;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int>mp;
        for(auto word:wordDict)
        {
            mp[word]=1;
        }
        vector<int>dp(s.size()+1,-1);
        return Solve(s,mp,0,dp);
    }
};
