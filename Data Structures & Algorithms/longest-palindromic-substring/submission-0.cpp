class Solution {
    private:
    string Solve(string s,int i,int j)
    {
        while(i>=0 && j<s.size())
        {
            if(s[i]==s[j])
            {
                i--;
                j++;
            }
            else
            break;
        }
        string str=s.substr(i+1,j-i-1);
        return str;
    }
public:
    string longestPalindrome(string s) {
        string ans;
        for(int i=0;i<s.size();i++)
        {
            //even length
            string evenLen=Solve(s,i,i+1);
            //odd length
            string oddLen=Solve(s,i,i);

            if(ans.size()<evenLen.size())
            ans=evenLen;
            
            if(ans.size()<oddLen.size())
            ans=oddLen;
        }
        return ans;

    }
};
