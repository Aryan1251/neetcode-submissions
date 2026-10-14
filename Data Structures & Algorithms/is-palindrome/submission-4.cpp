class Solution {
    bool isAlpha(char ch)
    {
        if(ch>='a' && ch<='z' || ch>='0' && ch<='9') return true;
        return false;
    }
public:
    bool isPalindrome(string s) {
        int n=s.size();
        for(auto &ch:s)
        {
            if(ch>='A' && ch<='Z')
            {
                ch=ch+32;
            }
        }
        int i=0,j=n-1;
        while(i<j)
        {
            if(isAlpha(s[i]) && isAlpha(s[j]))
            {
                if(s[i]==s[j])
                {
                    i++;
                    j--;
                }else return false;
            }
            else if(isAlpha(s[i])) j--;
            else if(isAlpha(s[j])) i++;
            else
            {
                i++;
                j--;
            }
        }
        return true;
    }
};
