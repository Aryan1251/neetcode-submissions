class Solution {
    int Solve(string s,int i,int j)
    {
        int cnt=0,n=s.size();
        while(i>=0 && j<n && s[i]==s[j])
        {
            i--;
            j++;
            cnt++;
        }
        return cnt;
    }
public:
    int countSubstrings(string s) {
        int cnt=0,n=s.size();
        for(int i=0;i<n;i++)
        {
            cnt+=Solve(s,i,i);
            cnt+=Solve(s,i,i+1);
        }
        return cnt;
    }
};
