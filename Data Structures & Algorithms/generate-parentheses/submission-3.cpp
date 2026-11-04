class Solution {
    void Solve(int n,int opCnt,int clCnt,string& str,vector<string>& ans)
    {
        if(opCnt==n && clCnt==n)
        {
            ans.push_back(str);
            return ;
        }

        if(opCnt<n)
        {
            str+='(';
            opCnt++;
            Solve(n,opCnt,clCnt,str,ans);
            opCnt--;
            str.pop_back();
        }
        if(clCnt<n && clCnt<opCnt)
        {
            str+=')';
            clCnt++;
            Solve(n,opCnt,clCnt,str,ans);
            clCnt--;
            str.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string str;
        vector<string>ans;
        Solve(n,0,0,str,ans);
        return ans;
    }
};
