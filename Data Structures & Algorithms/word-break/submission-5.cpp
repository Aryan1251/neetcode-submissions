class Solution {
    bool Solve(string s,unordered_map<string,int>& mp,vector<int>& dp,int ind)
    {
        if(ind>=s.size()) return 1;
        if(dp[ind]!=-1) return dp[ind];
        
        string str;
        bool op=false;
        for(int i=ind;i<s.size();i++)
        {
            str+=s[i];
            if(mp.find(str)!=mp.end())
            {
                bool ans=Solve(s,mp,dp,i+1);
                op=op|ans;
            }
        }
        return dp[ind]= op;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int>mp;
        int n=s.size();
        vector<int>dp(n+1,-1);
        for(auto word: wordDict)
        {
            mp[word]=1;
        }
        bool ans=Solve(s,mp,dp,0);
        return ans;
    }
};
