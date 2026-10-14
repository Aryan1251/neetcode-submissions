class Solution {
    int Solve(string s,int index)
    {
        if(index==s.size()-1)
        {
            if(s[index]>='1') return 1;
            else return 0;
        }
        if(index>=s.size()) return 1;

        //1 index up
        int cnt=0;

        if(s[index]>='1' && s[index]<='9')
        cnt+=Solve(s,index+1);

        //2 index up
        if((s[index]=='1') || (s[index]=='2' && s[index+1]<='6'))
        cnt+=Solve(s,index+2);

        return cnt;
    }
public:
    int numDecodings(string s) {
        int ans=Solve(s,0);
        return ans;
    }
};
