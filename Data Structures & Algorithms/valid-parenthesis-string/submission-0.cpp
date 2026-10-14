class Solution {
    bool Solve(string s,int ind,int op)
    {
        if(ind>=s.size())
        {
            if(op==0) return 1;
            return 0;
        }

        if(s[ind]=='(')
        return Solve(s,ind+1,op+1);

        else if(s[ind]==')')
        {
            if(op>0)
            return Solve(s,ind+1,op-1);
            else return false;
        }
        else
        {
            bool op1=Solve(s,ind+1,op+1);
            bool op2=false;
            if(op>0) op2=Solve(s,ind+1,op-1);
            bool op3=Solve(s,ind+1,op);
            return op1|op2|op3;
        }
        return true;
    }
public:
    bool checkValidString(string s) {
        bool ans=Solve(s,0,0);
        return ans;
    }
};
