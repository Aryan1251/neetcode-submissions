class Solution {
    private:
    int Solve(string s,int i,int j)
    {
        int cnt=0;
        int n=s.size();
        while(i>=0 && j<n)
        {
            if(s[i]==s[j])
            {
                cnt++;
                i--;
                j++;
            }else break;
        }
        return cnt;
    }
public:
    int countSubstrings(string s) {
        int n=s.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            //even Palin
            cnt+=Solve(s,i,i+1);

            //odd palin
            cnt+=Solve(s,i,i);
        }
        return cnt;
    }
};
