class Solution {
    int Solve(int a,int b,string token)
    {
        int res=1;
        if(token=="+")
        res=b+a;
        else if(token=="-")
        res=b-a;
        else if(token=="*")
        res=b*a;
        else if(token=="/")
        res=b/a;
        return res;
    }
public:
    int evalRPN(vector<string>& tokens) {
       stack<int>st;
       for(auto token: tokens)
       {
        if(token=="+" || token=="-" || token=="*" || token=="/")
        {
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            int res=Solve(a,b,token);
            st.push(res);
        }else
        {
            st.push(stoi(token));
        }
        }
       return st.top(); 
    }
};
