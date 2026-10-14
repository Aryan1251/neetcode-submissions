class Solution {
    bool chkPalin(string s)
    {
        int n=s.size();
        int i=0,j=n-1;
        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }else
            return false;
        }
        return true;
    }
    void Solve(string s,int index,vector<string>v,vector<vector<string> >& ans)
    {
        if(index>=s.size())
        {
            ans.push_back(v);
            return ;
        }

        string str;
        for(int i=index;i<s.size();i++)
        {
            str+=s[i];
            if(chkPalin(str))
            {
                v.push_back(str);
                Solve(s,i+1,v,ans);
                v.pop_back();
            }
        }
        return ;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> >ans;
        vector<string>v;
        Solve(s,0,v,ans);
        return ans;
    }
};
