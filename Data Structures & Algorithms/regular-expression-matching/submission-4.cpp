class Solution {
    bool Solve(string s,string p)
    {
        if(s.empty() && p.empty()) return true;
        if(p.empty())
        {
            if(s.empty()) return true;
            return false;
        }

        if(p[1]=='*')
        {
            bool take=false;
            if(!s.empty() && (p[0]==s[0] || p[0]=='.'))
            {
                take=Solve(s.substr(1),p);
            }
            bool not_take=Solve(s,p.substr(2));
            return take||not_take;
        }else
        {
            bool op1=false;
            if(!s.empty() && (p[0]==s[0] || p[0]=='.'))
            {
                op1=Solve(s.substr(1),p.substr(1));
                return op1;
            }
            else return false;
        }
    }
public:
    bool isMatch(string s, string p) {
        bool ans=Solve(s,p);
        return ans;
    }
};
