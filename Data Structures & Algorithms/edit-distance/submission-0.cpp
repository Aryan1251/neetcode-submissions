class Solution {
    int Solve(string word1,string word2,int ind1,int ind2,vector<vector<int> >& dp)
    {
        if(ind1>=word1.size() && ind2>=word2.size()) return 0;
        if(ind1>=word1.size())
        {
            return word2.size()-ind2;
        }
        if(ind2>=word2.size())
        {
            return word1.size()-ind1;
        }
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];

        int ans=0;
        if(word1[ind1]==word2[ind2])
        ans=Solve(word1,word2,ind1+1,ind2+1,dp);
        else
        {
            int op1=1+Solve(word1,word2,ind1,ind2+1,dp);
            int op2=1+Solve(word1,word2,ind1+1,ind2,dp);
            int op3=1+Solve(word1,word2,ind1+1,ind2+1,dp);

            return dp[ind1][ind2]= min(op1,min(op2,op3));
        }
        return dp[ind1][ind2]= ans;
    }
public:
    int minDistance(string word1, string word2) {
        vector<vector<int> >dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        int ans=Solve(word1,word2,0,0,dp);
        return ans;
    }
};
