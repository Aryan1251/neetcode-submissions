class Solution {
    int Solve(string s,int i,int j)
    {
        int cnt=0;
        while(i>=0 && j<s.size() && s[i]==s[j])
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
            //even len
            cnt+=Solve(s,i,i+1);

            //odd len
            cnt+=Solve(s,i,i);
        }
        return cnt;
    }
};
