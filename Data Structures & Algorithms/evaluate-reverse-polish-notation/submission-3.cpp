class Solution {
    bool isChar(string token)
    {
        if(token=="+" || token=="-" || token=="*" || token=="/")
        return true;
        return false;
    }
    int getResult(int a,int b,string token)
    {
        if(token=="+") return a+b;
        if(token=="-") return a-b;
        if(token=="*") return a*b;
        if(token=="/" && b!=0) return a/b;
        return 1;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto token: tokens)
        {
            if(isChar(token))
            {
                int top1=st.top();
                st.pop();
                int top2=st.top();
                st.pop();
                int res=getResult(top2,top1,token);
                st.push(res);
            }else
            {
                int num=stoi(token);
                st.push(num);
            }
        }
        return st.top();
    }
};
