class Solution {
public:
    bool checkValidString(string s) {
        stack<pair<int,char> >st1;
        stack<pair<int,char> >st2;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            char ch=s[i];
            if(ch=='(')
            st1.push({i,ch});
            else if(ch=='*')
            {
                st2.push({i,ch});
            }
            else
            {
                while(!st1.empty() && st1.top().second!='(')
                {
                    char ch=st1.top().second;
                    st1.pop();
                }
                if(!st1.empty()) st1.pop();
                else
                {
                    if(!st2.empty()) st2.pop();
                    else return false;
                }
            }
        }
        if(st1.empty()) return true;
        else
        {
            while(!st1.empty() && !st2.empty())
            {
                char ch=st1.top().second;
                int ind1=st1.top().first;
                int ind2=st2.top().first;
                st2.pop();
                st1.pop();
                if(ind1>ind2) return false;
            }
        }
        return st1.empty();
    }
};
