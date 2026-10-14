class Solution {
    void Solve(int op,int cl,int opCnt,vector<string>& ans,string s,int n)
    {
        if(op==n && cl==n)
        {
            ans.push_back(s);
            return ;
        }

        if(op<n)
        {
            s+='(';
            Solve(op+1,cl,opCnt+1,ans,s,n);
            s.pop_back();
        }
        if(cl<n)
        {
            if(opCnt>0)
            {
                s+=')';
                Solve(op,cl+1,opCnt-1,ans,s,n);
                s.pop_back();
            }
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s;
        Solve(0,0,0,ans,s,n);
        return ans;
    }
};
