class Solution {
    bool isPalin(string s)
    {
        int i=0,j=s.size()-1;
        while(i<=j)
        {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void Solve(string s,int index,vector<vector<string> >& ans,vector<string> v)
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
            if(isPalin(str))
            {
                v.push_back(str);
                Solve(s,i+1,ans,v);
                v.pop_back();
            }
        }
        return ;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> >ans;
        Solve(s,0,ans,{});
        return ans;
    }
};
