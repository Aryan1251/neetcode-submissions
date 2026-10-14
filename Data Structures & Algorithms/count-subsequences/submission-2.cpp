class Solution {
    int Solve(string s,string t,int i,int j)
    {
        if(j>=t.size()) return 1;

        if(i>=s.size()) return 0;

        int op1=0,op2=0;
        if(s[i]==t[j])
        op1=Solve(s,t,i+1,j+1);

        op2=Solve(s,t,i+1,j);

        return op1+op2;
    }
public:
    int numDistinct(string s, string t) {
        int ans=Solve(s,t,0,0);
        return ans;
    }
};
