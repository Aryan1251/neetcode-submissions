class Solution {
    string Solve(string s,int i,int j)
    {
        int n=s.size();
        while(i>=0 && j<n)
        {
            if(s[i]==s[j])
            {
                i--;
                j++;
            }else
            break;
        }
        string str=s.substr(i+1,j-i-1);
        return str;
    }
public:
    string longestPalindrome(string s) {
        string ans;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            //even palin
            string s1=Solve(s,i,i+1);
            //odd palin
            string s2=Solve(s,i,i);

            if(s1.size()>s2.size())
            {
                if(s1.size()>ans.size()) ans=s1;
            }else
            {
                if(s2.size()>ans.size()) ans=s2;
            }
        }
        return ans;
    }
};
