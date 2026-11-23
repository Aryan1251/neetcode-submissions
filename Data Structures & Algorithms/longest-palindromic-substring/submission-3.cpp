class Solution {
    string Solve(string& s,int i,int j)
    {
        int n=s.size();
        while(i>=0 && j<n && s[i]==s[j])
        {
            i--;
            j++;
        }
        string str=s.substr(i+1,j-i-1);
        return str;
    }
public:
    string longestPalindrome(string s) {
        int n=s.size();
        string ans;

        for(int i=0;i<n;i++)
        {
            //odd length
            string str1=Solve(s,i,i);

            //even length
            string str2=Solve(s,i,i+1);

            if(ans.size()<str1.size()) ans=str1;
            if(ans.size()<str2.size()) ans=str2;
        }
        return ans;
    }
};
