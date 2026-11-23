class Solution {
    bool Solve(string& s,vector<int>& dp,unordered_map<string,int>& mp,int ind)
    {
        //bc
        if(ind>=s.size())
        return 1;
        if(dp[ind]!=-1) return dp[ind];

        string str;
        bool ans=false;
        for(int i=ind;i<s.size();i++)
        {
            str+=s[i];
            if(mp.find(str)!=mp.end())
            {
                ans=ans|Solve(s,dp,mp,i+1);
            }
        }
        return dp[ind]=ans;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int>mp;
        for(auto word: wordDict)
        {
            mp[word]=1;
        }
        vector<int>dp(s.size()+1,-1);
        return Solve(s,dp,mp,0);
    }
};
