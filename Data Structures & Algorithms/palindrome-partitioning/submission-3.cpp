class Solution {
    bool isPalin(string s)
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
    void Solve(string s,vector<vector<string> >& ans,vector<string>& v,int ind)
    {
        if(ind>=s.size())
        {
            ans.push_back(v);
            return ;
        }

        string str;
        for(int i=ind;i<s.size();i++)
        {
            str+=s[i];
            if(isPalin(str))
            {
                v.push_back(str);
                Solve(s,ans,v,i+1);
                v.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        if(s.empty()) return {};
        vector<vector<string> >ans;
        vector<string>v;
        Solve(s,ans,v,0);
        return ans;
    }
};
