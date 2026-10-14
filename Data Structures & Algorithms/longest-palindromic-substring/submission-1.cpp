class Solution {
    string Solve(string s,int i,int j)
    {
        string str;
        while(i>=0 && j<s.size() && s[i]==s[j])
        {
            i--;
            j++;
        }
        str=s.substr(i+1,j-i-1);
        return str;
    }
public:
    string longestPalindrome(string s) {
        int n=s.size();
        string str;
        for(int i=0;i<n;i++)
        {
            //even Case
            string s1=Solve(s,i,i+1);
            
            //odd Case
            string s2=Solve(s,i,i);

            if(s1.size()>str.size()) str=s1;
            if(s2.size()>str.size()) str=s2;
        }
        return str;
    }
};
