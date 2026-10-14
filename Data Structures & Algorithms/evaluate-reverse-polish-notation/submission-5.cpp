class Solution {
    pair<int,int> getNumbers(string &a,string &b)
    {
        auto num1=stoi(a);
        auto num2=stoi(b);
        return {num1,num2};
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<string>st;
        int n=tokens.size();

        for(int i=0;i<n;i++)
        {
            string str=tokens[i];
            if(str=="+")
            {
                auto a=st.top();
                st.pop();
                auto b=st.top();
                st.pop();
                auto p=getNumbers(a,b);
                int res=p.first+p.second;
                st.push(to_string(res));
            }else if(str=="*")
            {
                auto a=st.top();
                st.pop();
                auto b=st.top();
                st.pop();
                auto p=getNumbers(a,b);
                int res=p.first*p.second;
                st.push(to_string(res));
            }else if(str=="-")
            {
                auto a=st.top();
                st.pop();
                auto b=st.top();
                st.pop();
                auto p=getNumbers(a,b);
                int res=p.second-p.first;
                st.push(to_string(res));
            }else if(str=="/")
            {
                auto a=st.top();
                st.pop();
                auto b=st.top();
                st.pop();
                auto p=getNumbers(a,b);
                int res=p.second/p.first;
                st.push(to_string(res));
            }else st.push(str);
        }
        string s=st.top();
        return stoi(s);
    }
};
