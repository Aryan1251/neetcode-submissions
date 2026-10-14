class Solution {
    private:
    bool isPalin(string &s)
    {
        int i=0,j=s.size()-1;
        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }else return false;
        }
        return true;
    }
    void Solve(string s,int ind,vector<string>str,vector<vector<string> >& ans)
    {
        if(ind>=s.size())
        {
            ans.push_back(str);
            return ;
        }
        string s1;
        for(int i=ind;i<s.size();i++)
        {
            s1+=s[i];
            if(isPalin(s1))
            {
                str.push_back(s1);
                Solve(s,i+1,str,ans);
                str.pop_back();
            }
        }
        return ;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string>str;
        vector<vector<string> >ans;
        Solve(s,0,str,ans);
        return ans;
    }
};
