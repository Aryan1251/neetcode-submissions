class Solution {
    int Solve(string word1,string word2,int i,int j,vector<vector<int> >& dp)
    {
        if(i>=word1.size())
        {
            return word2.size()-j;
        }
        if(j>=word2.size())
        {
            return word1.size()-i;
        }

        int op=0;
        if(word1[i]==word2[j]) 
        op=Solve(word1,word2,i+1,j+1,dp);

        else
        {
            int op1=1+Solve(word1,word2,i,j+1,dp); //insert
            int op2=1+Solve(word1,word2,i+1,j+1,dp); //replace
            int op3=1+Solve(word1,word2,i+1,j,dp);//delete
            return min(op1,min(op2,op3));
        }
        return op;
    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int> >dp(n+1,vector<int>(m+1,-1));
       int ans= Solve(word1,word2,0,0,dp);
       return ans;
    }
};
