class Solution {
    void getResult(int op,int cl,vector<string>& ans,string str)
    {
        if(op==0 && cl==0)
        {
            ans.push_back(str);
            return ;
        }

        if(op)
        {
            str.push_back('(');
            getResult(op-1,cl,ans,str);
            str.pop_back();
        }
        if(cl>op)
        {
            str.push_back(')');
            getResult(op,cl-1,ans,str);
            str.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string str;
        vector<string>ans;
        getResult(n,n,ans,str);
        return ans;
    }
};
