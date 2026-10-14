class Solution {
    private:
    int claculate(int a,int b,string ch)
    {
        if(ch=="+") return a+b;
        else if(ch=="-") return a-b;
        else if(ch=="*") return a*b;
        else if(ch=="/")
        {
            if(b!=0) return a/b;
            return 0;
        }
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<string>st;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="-" || tokens[i]=="+" || tokens[i]=="/" || tokens[i]=="*")
            {
                string s1=st.top();
                st.pop();
                string s2=st.top();
                st.pop();
                int a=stoi(s1);
                int b=stoi(s2);
                int ans=claculate(b,a,tokens[i]);
                string s=to_string(ans);
                st.push(s);
            }else
            st.push(tokens[i]);
        }
        int ans=stoi(st.top());
        return ans;
    }
};
