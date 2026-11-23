class Solution {
    int Solve(string s,int i,int j)
    {
        int n=s.size(),cnt=0;
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
        int n=s.size();
        int cnt=0;

        for(int i=0;i<n;i++)
        {
            //odd length
            cnt+=Solve(s,i,i);

            //even length
            cnt+=Solve(s,i,i+1);
        }
        return cnt;
    }
};
