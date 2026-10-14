class Solution {
    int Solve(string word1,string word2,int i,int j)
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
        op=Solve(word1,word2,i+1,j+1);

        else
        {
            int op1=1+Solve(word1,word2,i,j+1); //insert
            int op2=1+Solve(word1,word2,i+1,j+1); //replace
            int op3=1+Solve(word1,word2,i+1,j);//delete
            return min(op1,min(op2,op3));
        }
        return op;
    }
public:
    int minDistance(string word1, string word2) {
       int ans= Solve(word1,word2,0,0);
       return ans;
    }
};
