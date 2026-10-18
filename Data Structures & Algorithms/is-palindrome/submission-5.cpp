class Solution {
    bool isAlpha(char ch)
    {
        if((ch>='0' && ch<='9') || (ch>='a' && ch<='z')) return 1;
        return 0;
    }
public:
    bool isPalindrome(string s) {
        int n=s.size();
        int i=0,j=n-1;
        for(auto &ch: s)
        {
            if(ch>='A' && ch<='Z') ch=ch+32;
        }
        while(i<=j)
        {
            if(isAlpha(s[i]) && isAlpha(s[j]))
            {
                if(s[i]==s[j])
                {
                    i++;
                    j--;
                }else return false;
            }else if(!isAlpha(s[i])) i++;
            else j--;
        }
        return true;
    }
};
