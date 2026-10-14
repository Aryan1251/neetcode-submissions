class Solution {
    private:
    void Solve(int op,int cl,int opCnt,int clCnt,string str,vector<string>& strs)
    {
        if(op==opCnt && cl==clCnt)
        {
            strs.push_back(str);
            return ;
        }

        if(op<opCnt)
        {
            str+='(';
            Solve(op+1,cl,opCnt,clCnt,str,strs);
            str.pop_back();
        }
        if(cl<clCnt && op>cl)
        {
            str+=')';
            Solve(op,cl+1,opCnt,clCnt,str,strs);
            str.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>strs;
        string str;
        Solve(0,0,n,n,str,strs);
        return strs;
    }
};
